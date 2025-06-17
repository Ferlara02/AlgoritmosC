#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct {
    double x, y, z;
} Vec3;

typedef struct {
    Vec3 point;
    Vec3 normal;
    double t;
    Vec3 color;
} Hit;

typedef struct {
    Vec3 position;
    Vec3 color;
    double intensity;
} Light;

Vec3 vec_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 vec_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 vec_mul(Vec3 v, double t) {
    return (Vec3){v.x * t, v.y * t, v.z * t};
}

Vec3 vec_mul_vec(Vec3 a, Vec3 b) {
    return (Vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

double vec_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 vec_normalize(Vec3 v) {
    double len = sqrt(vec_dot(v, v));
    return vec_mul(v, 1.0 / len);
}

Vec3 vec_clamp(Vec3 v) {
    if (v.x > 1.0) v.x = 1.0; if (v.x < 0.0) v.x = 0.0;
    if (v.y > 1.0) v.y = 1.0; if (v.y < 0.0) v.y = 0.0;
    if (v.z > 1.0) v.z = 1.0; if (v.z < 0.0) v.z = 0.0;
    return v;
}

int hit_sphere(Vec3 center, double radius, Vec3 origin, Vec3 dir, Hit *hit) {
    Vec3 oc = vec_sub(origin, center);
    double a = vec_dot(dir, dir);
    double b = 2.0 * vec_dot(oc, dir);
    double c = vec_dot(oc, oc) - radius * radius;
    double disc = b*b - 4*a*c;

    if (disc < 0.0) return 0;

    double t = (-b - sqrt(disc)) / (2.0 * a);
    if (t < 0.001) return 0;

    hit->t = t;
    hit->point = vec_add(origin, vec_mul(dir, t));
    hit->normal = vec_normalize(vec_sub(hit->point, center));
    hit->color = (Vec3){1.0, 1.0, 1.0};
    return 1;
}

int hit_plane(double y, Vec3 origin, Vec3 dir, Hit *hit) {
    if (fabs(dir.y) < 1e-6) return 0;

    double t = (y - origin.y) / dir.y;
    if (t < 0.001) return 0;

    hit->t = t;
    hit->point = vec_add(origin, vec_mul(dir, t));
    hit->normal = (Vec3){0.0, 1.0, 0.0};
    hit->color = (Vec3){0.6, 0.6, 0.6};
    return 1;
}

int is_in_shadow(Vec3 point, Vec3 light_dir, double light_dist) {
    Hit tmp;
    Vec3 origin = vec_add(point, vec_mul(light_dir, 0.001));
    if (hit_sphere((Vec3){0, 0, -1}, 0.5, origin, light_dir, &tmp)) {
        return tmp.t < light_dist;
    }
    return 0;
}

Vec3 ray_color(Vec3 origin, Vec3 dir, Light *lights, int num_lights) {
    Hit closest;
    int has_hit = 0;

    Hit h1;
    if (hit_sphere((Vec3){0, 0, -1}, 0.5, origin, dir, &h1)) {
        closest = h1;
        has_hit = 1;
    }

    Hit h2;
    if (hit_plane(-0.5, origin, dir, &h2)) {
        if (!has_hit || h2.t < closest.t) {
            closest = h2;
            has_hit = 1;
        }
    }

    if (!has_hit) return (Vec3){0.0, 0.0, 0.0};

    Vec3 final = {0, 0, 0};

    for (int i = 0; i < num_lights; ++i) {
        Vec3 to_light = vec_sub(lights[i].position, closest.point);
        double dist = sqrt(vec_dot(to_light, to_light));
        Vec3 light_dir = vec_normalize(to_light);

        double dot = vec_dot(closest.normal, light_dir);
        double factor = is_in_shadow(closest.point, light_dir, dist) ? 0.1 : (dot > 0 ? dot : 0.0);

        Vec3 contrib = vec_mul_vec(closest.color, lights[i].color);
        contrib = vec_mul(contrib, factor * lights[i].intensity);
        final = vec_add(final, contrib);
    }

    return vec_clamp(final);
}

int main() {
    FILE *f = fopen("scene.ppm", "w");
    fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    Vec3 lower_left = {-2.0, -1.0, -1.0};
    Vec3 horiz = {4.0, 0.0, 0.0};
    Vec3 vert = {0.0, 2.0, 0.0};
    Vec3 origin = {0.0, 0.0, 0.0};

    Light lights[2] = {
        {{2, 5, 0}, {0.7, 0.4, 1.0}, 1.0},     // violeta claro
        {{-5, 2, -3}, {1.0, 0.8, 0.8}, 0.4}    // luz cÃ¡lida
    };

    for (int j = HEIGHT - 1; j >= 0; j--) {
        for (int i = 0; i < WIDTH; i++) {
            double u = (double)i / WIDTH;
            double v = (double)j / HEIGHT;
            Vec3 dir = vec_add(lower_left, vec_add(vec_mul(horiz, u), vec_mul(vert, v)));
            dir = vec_sub(dir, origin);
            Vec3 col = ray_color(origin, dir, lights, 2);

            int r = (int)(255.99 * col.x);
            int g = (int)(255.99 * col.y);
            int b = (int)(255.99 * col.z);
            fprintf(f, "%d %d %d\n", r, g, b);
        }
    }

    fclose(f);
    printf("Render guardado como scene.ppm\n");
    return 0;
}
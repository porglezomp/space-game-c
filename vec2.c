#include "vec2.h"
#include "math.h"

// Provide some useful constants
vec2 v2zero = {0, 0};
vec2 v2one = {1, 1};
vec2 v2right = {1, 0};
vec2 v2left = {-1, 0};
vec2 v2up = {0, 1};
vec2 v2down = {0, -1};

vec2f v2fzero = {0, 0};
vec2f v2fone = {1, 1};
vec2f v2fright = {1, 0};
vec2f v2fleft = {-1, 0};
vec2f v2fup = {0, 1};
vec2f v2fdown = {0, -1};

vec2 v2angle(double angle) {
    double rads = angle/180*M_PI;
    // Swap sin and cos so that 0 degrees points up
    // I think this makes angles increase clockwise?
    vec2 res = {sin(rads), cos(rads)};
    return res;
}

vec2 v2ftov2(const vec2f *v2) { return (vec2) {v2->x, v2->y}; }

vec2f v2tov2f(const vec2 *v) { return (vec2f) {v->x, v->y}; }

// ==========================================================================//
// vec2 (double) arithmetic                                                  //
// ==========================================================================//

// lhs + rhs
vec2 v2add(const vec2 *lhs, const vec2 *rhs) {
    vec2 res = {lhs->x + rhs->x, lhs->y + rhs->y};
    return res;
}

// lhs += rhs
void v2inc(vec2 *lhs, const vec2 *rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
}

// lhs - rhs
vec2 v2sub(const vec2 *lhs, const vec2 *rhs) {
    vec2 res = {lhs->x - rhs->x, lhs->y - rhs->y};
    return res;
}

// lhs -= rhs
void v2dec(vec2 *lhs, const vec2 *rhs) {
    lhs->x -= rhs->x;
    lhs->y -= rhs->y;
}

// vec * scalar
vec2 v2mul(const vec2 *vec, double s) {
    vec2 res = {vec->x * s, vec->y * s};
    return res;
}

// vec *= scalar
void v2muli(vec2 *vec, double s) {
    vec->x *= s;
    vec->y *= s;
}

// ==========================================================================//
// vec2f (float) arithmetic                                                  //
// ==========================================================================//

void v2finc(vec2f *lhs, const vec2f *rhs) {
    lhs->x += rhs->x;
    lhs->y += rhs->y;
}

void v2fmuli(vec2f *vec, float s) {
    vec->x *= s;
    vec->y *= s;
}

// ==========================================================================//
// Vector math for vec2 (double)                                             //
// ==========================================================================//

// dot product
double v2dot(const vec2 *lhs, const vec2 *rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y);
}

// project lhs onto rhs
vec2 v2proj(const vec2 *lhs, const vec2 *rhs) {
    return v2mul(rhs, v2dot(lhs, rhs));
}

// return the length of vec
double v2len(const vec2 *vec) {
    return sqrt(vec->x*vec->x + vec->y*vec->y);
}

// return a normalize (length 1) version of vec
vec2 v2normed(const vec2 *vec) {
    double recip_len = 1/v2len(vec);
    return v2mul(vec, recip_len);
}

// normalize the vector in place
void v2norm(vec2 *vec) {
    double recip_len = 1/v2len(vec);
    v2muli(vec, recip_len);
}

// ==========================================================================//
// Vector math for vec2d (float)                                             //
// ==========================================================================//

float v2fdot(const vec2f *lhs, const vec2f *rhs) {
    return (lhs->x * rhs->x) + (lhs->y * rhs->y);
}

float v2flen(const vec2f *vec) {
    return sqrt(vec->x*vec->x + vec->y*vec->y);
}

void v2fnorm(vec2f *vec) {
    float recip_len = 1/v2flen(vec);
    v2fmuli(vec, recip_len);
}

/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <math.h>
#include <cinttypes>
#include <random>
#include <ctime>

static struct MathClass {
    std::mt19937_64 gen;
    std::uniform_real_distribution<double> dist;

    MathClass()
    {
        std::random_device rd;
        gen = std::mt19937_64(rd());
        dist = std::uniform_real_distribution<double>(0, 1.0);
    }
    constexpr MathClass* operator->()
    {
        return this;
    }

    float round(float a1) { return ::round(a1); }
    double round(double a1) { return ::round(a1); }

    float pow(float a1, float a2) { return ::pow(a1, a2); }
    double pow(double a1, double a2) { return ::pow(a1, a2); }

    float log10(float arg) { return ::log10(arg); }
    double log10(double arg) { return ::log10(arg); }

    float log(float arg) { return ::log(arg); }
    double log(double arg) { return ::log(arg); }

    float ceil(float arg) { return (int) ::ceil(arg); }
    double ceil(double arg) { return (int) ::ceil(arg); }

    float floor(float arg) { return (int) ::floor(arg); }
    double floor(double arg) { return (int) ::floor(arg); }

    float exp(float arg) { return ::exp(arg); }
    double exp(double arg) { return ::exp(arg); }

    float cbrt(float arg) { return ::cbrt(arg); }
    double cbrt(double arg) { return ::cbrt(arg); }

    float acosh(float arg) { return ::acosh(arg); }
    double acosh(double arg) { return ::acosh(arg); }

    float asinh(float arg) { return ::asinh(arg); }
    double asinh(double arg) { return ::asinh(arg); }

    float atanh(float arg) { return ::atanh(arg); }
    double atanh(double arg) { return ::atanh(arg); }

    float cosh(float arg) { return ::cosh(arg); }
    double cosh(double arg) { return ::cosh(arg); }

    float sinh(float arg) { return ::sinh(arg); }
    double sinh(double arg) { return ::sinh(arg); }

    float tanh(float arg) { return ::tanh(arg); }
    double tanh(double arg) { return ::tanh(arg); }

    float acos(float arg) { return ::acos(arg); }
    double acos(double arg) { return ::acos(arg); }

    float asin(float arg) { return ::asin(arg); }
    double asin(double arg) { return ::asin(arg); }

    float atan(float arg) { return ::atan(arg); }
    double atan(double arg) { return ::atan(arg); }

    float cos(float arg) { return ::cos(arg); }
    double cos(double arg) { return ::cos(arg); }

    float sin(float arg) { return ::sin(arg); }
    double sin(double arg) { return ::sin(arg); }

    float tan(float arg) { return ::tan(arg); }
    double tan(double arg) { return ::tan(arg); }

    float sqrt(float arg) { return ::sqrt(arg); }
    double sqrt(double arg) { return ::sqrt(arg); }

    float abs(float arg) { return ::abs(arg); }
    double abs(double arg) { return ::abs(arg); }

    int32_t abs(int32_t arg) { return ::abs(arg); }
    int64_t abs(int64_t arg) { return ::abs(arg); }

    float random() { return dist(gen); }
} Math;
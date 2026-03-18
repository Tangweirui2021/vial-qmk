// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
#define RGB_MATRIX_EFFECT_PIXEL_RAIN
RGB_MATRIX_EFFECT(PIXEL_RAIN)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#        ifdef EFFECT_LAYERS
#            define PIXEL_RAIN_REGION_COUNT EFFECT_LAYERS
#        else
#            define PIXEL_RAIN_REGION_COUNT 2
#        endif

static fast_timer_t timer[PIXEL_RAIN_REGION_COUNT] = {0};

void PIXEL_RAIN_init(void) {
    for (uint8_t region = 0; region < PIXEL_RAIN_REGION_COUNT; ++region) {
        timer[region] = 0;
    }
}

bool PIXEL_RAIN(effect_params_t* params) {
    static uint16_t index[PIXEL_RAIN_REGION_COUNT];
    static bool     timer_update[PIXEL_RAIN_REGION_COUNT];
    uint8_t         region = params->region;

    if (params->init) {
        index[region]        = RGB_MATRIX_LED_COUNT + 1;
        timer[region]        = 0;
        timer_update[region] = false;
    }

    if (params->iter == 0) {
        if (timer_elapsed_fast(timer[region]) > (320 - rgb_matrix_config.speed)) {
            index[region]        = random8_max(RGB_MATRIX_LED_COUNT);
            timer_update[region] = true;
        }
    } else {
        if (timer_update[region]) {
            timer[region]        = timer_read_fast();
            timer_update[region] = false;
        }
    }

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    if (led_min <= index[region] && index[region] < led_max && HAS_ANY_FLAGS(g_led_config.flags[index[region]], params->flags)) {
        hsv_t hsv = (random8() & 2) ? (hsv_t){0, 0, 0} : (hsv_t){random8(), random8_min_max(127, 255), rgb_matrix_config.hsv.v};
        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_region_set_color(region, index[region], rgb.r, rgb.g, rgb.b);

        index[region] = RGB_MATRIX_LED_COUNT + 1;
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // ENABLE_RGB_MATRIX_PIXEL_RAIN

#include "main_page.h"

    static lv_obj_t * main_screen;
    static lv_obj_t * temperature_card;
    static lv_obj_t * temperature_card_header;
    static lv_obj_t * pressure_card;
    static lv_obj_t * pressure_card_header;
    static lv_obj_t * humidity_card;
    static lv_obj_t * humidity_card_header;
    static lv_obj_t * co2_card;
    static lv_obj_t * co2_card_header;
    static lv_obj_t * time_card;
    static lv_obj_t * top_panel;
    static lv_obj_t * temperature_header_label;
    static lv_obj_t * pressure_header_label;
    static lv_obj_t * humidity_header_label;
    static lv_obj_t * co2_header_label;

static void place_card(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parent, lv_obj_t ** card, lv_obj_t ** header, lv_obj_t ** header_label);
static void place_headless_card(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parent, lv_obj_t ** card);

void
init_main_page(void) {
    main_screen = lv_obj_create(NULL);
    place_card(150, 150, 5, 55, main_screen, &temperature_card, &temperature_card_header, &temperature_header_label);
    place_card(150, 100, 5, 215, main_screen, &pressure_card, &pressure_card_header, &pressure_header_label);
    place_card(150, 100, 165, 215, main_screen, &humidity_card, &humidity_card_header, &humidity_header_label);
    place_card(150, 100, 325, 215, main_screen, &co2_card, &co2_card_header, &co2_header_label);
    place_headless_card(310, 150, 165, 55, main_screen, &time_card);
    place_headless_card(470, 40, 5, 5, main_screen, &top_panel);
    
    /* Uncommenting any of these lines leads to seg fault or assert at expression obj != NULL in lv_label.c:87*/
    lv_obj_set_style_bg_color (&top_panel , lv_color_make(120,120,120), 0); 
    lv_label_set_text(&temperature_header_label, "NOT WORKING");
}

void
load_main_page(void) {
    
    lv_scr_load(main_screen);
}

static void 
place_card(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parent, lv_obj_t ** card, lv_obj_t ** header, lv_obj_t ** header_label) {
    *card = lv_obj_create(parent);
    lv_obj_align(*card, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(*card, x_size, y_size);
    lv_obj_set_style_pad_all(*card,0,0);
    *header = lv_obj_create(*card);
    lv_obj_set_size(*header, x_size-4, 35);
    lv_obj_align(*header, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_border_side(*header, LV_BORDER_SIDE_NONE, 0);
    lv_obj_set_style_radius(*header, 0, 0);
    lv_obj_set_style_pad_all(*header,0,0);
    lv_obj_set_style_bg_color (*header , lv_color_make(120,120,120), 0);
    *header_label = lv_label_create(*header);
    lv_label_set_text(*header_label, "TEST");
}

static void 
place_headless_card(int x_size, int y_size, int x_offset, int y_offset, lv_obj_t * parent, lv_obj_t ** card) {
    *card = lv_obj_create(parent);
    lv_obj_align(*card, LV_ALIGN_TOP_LEFT, x_offset, y_offset);
    lv_obj_set_size(*card, x_size, y_size);
    lv_obj_set_style_pad_all(*card,0,0);
}

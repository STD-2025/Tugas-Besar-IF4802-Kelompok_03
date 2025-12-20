#pragma once

typedef struct {
    const int main_menu_content_width;
    const int main_menu_content_height;

    const int home_content_width;
    const int home_content_height;

    const int max_bus;
    const int max_market_bus;

    const int initial_m_bus_count;
    const double initial_money;

    const int market_refresh_interval;
} Config;

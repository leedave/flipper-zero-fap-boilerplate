#include "../boilerplate.h"

void boilerplate_scene_6_callback(void* context, int32_t number) {
    Boilerplate* app = context;
    app->current_number = number;
    view_dispatcher_send_custom_event(app->view_dispatcher, 0);
}

void boilerplate_scene_scene_6_on_enter(void* context) {
    furi_assert(context);
    Boilerplate* app = context;
    NumberInput* number_input = app->number_input;

    char str[50];
    int32_t min_value = -128;
    int32_t max_value = 2048;
    snprintf(str, sizeof(str), "Set Number (%ld - %ld)", min_value, max_value);

    number_input_set_header_text(number_input, str);
    number_input_set_result_callback(
        number_input,
        boilerplate_scene_6_callback,
        context,
        app->current_number,
        min_value,
        max_value);

    view_dispatcher_switch_to_view(app->view_dispatcher, BoilerplateViewIdNumberInput);
}

bool boilerplate_scene_scene_6_on_event(void* context, SceneManagerEvent event) {
    Boilerplate* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) { //Back button pressed
        scene_manager_previous_scene(app->scene_manager);
        return true;
    }
    return consumed;
}

void boilerplate_scene_scene_6_on_exit(void* context) {
    UNUSED(context);
}

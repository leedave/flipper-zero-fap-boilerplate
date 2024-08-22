#include "../boilerplate.h"

void boilerplate_scene_scene_5_text_input_callback(void* context) {
    furi_assert(context);
    Boilerplate* app = context;
    view_dispatcher_send_custom_event(app->view_dispatcher, 0);
}

void boilerplate_scene_scene_5_on_enter(void* context) {
    Boilerplate* app = context;
    TextInput* text_input = app->text_input;

    text_input_set_header_text(text_input, "This is a custom text");

    size_t enter_name_length = 32;
    text_input_set_result_callback(
        text_input,
        boilerplate_scene_scene_5_text_input_callback,
        context,
        app->text_store[0],
        enter_name_length,
        false);

    view_dispatcher_switch_to_view(app->view_dispatcher, BoilerplateViewIdTextInput);
}

bool boilerplate_scene_scene_5_on_event(void* context, SceneManagerEvent event) {
    Boilerplate* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) { //Back button pressed
        scene_manager_previous_scene(app->scene_manager);
        return true;
    }
    return consumed;
}

void boilerplate_scene_scene_5_on_exit(void* context) {
    UNUSED(context);
}

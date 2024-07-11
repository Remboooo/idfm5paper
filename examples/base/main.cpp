/* m5paper template
*/
#include "M5EPD.h"
#include <esp_task_wdt.h>

void setup()
{
    M5.begin();
}

void loop()
{
}

void loopTask(void *pvParameters)
{
    setup();
    for(;;) {
        micros(); //update overflow
        loop();
    }
}

extern "C" void app_main()
{
    initArduino();

    // Disable the task watchdog timer for the arduino core
    const esp_task_wdt_config_t esp_task_wdt_config = {
        .timeout_ms = CONFIG_ESP_INT_WDT_TIMEOUT_MS,
        .idle_core_mask = 3 & ~(1<<ARDUINO_RUNNING_CORE),
        .trigger_panic = true
    };
    esp_task_wdt_reconfigure(&esp_task_wdt_config);

    xTaskCreatePinnedToCore(loopTask, "loopTask", 8192, NULL, 1, NULL, ARDUINO_RUNNING_CORE);
}

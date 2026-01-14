#include "hal/adc/adc.h"
#include "hardware/adc.h"


uint8_t get_gpio_rp2_adc_channel(uint8_t channel){
    switch(channel){
        case RP2_ADC_CH0:
            return 26;
        case RP2_ADC_CH1:
            return 27;
        case RP2_ADC_CH2:
            return 28;
        case RP2_ADC_CH3:
            return 29;
        case RP2_ADC_TEMP:
            return 0;
        default:
            return 0;
    }
}


bool rp2_adc_init(rp2_adc_t* config){
    if(config->init_done)
        return true;

    adc_init();
    adc_gpio_init(get_gpio_rp2_adc_channel(config->adc_channel));
    adc_select_input(config->adc_channel);

    config->init_done = true;
    return config->init_done;
}


bool rp2_change_channel(rp2_adc_t* config, uint8_t new_channel){
    if(!config->init_done)
        return false;

    adc_gpio_init(get_gpio_rp2_adc_channel(new_channel));
    adc_select_input(new_channel);
    
    config->adc_channel = new_channel;
    return true;
}


uint16_t rp2_adc_read_raw(rp2_adc_t* config){
    if(!config->init_done)
        return 0;

    return adc_read();
}

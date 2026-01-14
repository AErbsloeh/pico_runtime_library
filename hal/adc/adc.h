#ifndef HAL_ADC_H_
#define HAL_ADC_H_


#include "pico/stdlib.h"


#define RP2_ADC_CH0     0x00
#define RP2_ADC_CH1     0x01
#define RP2_ADC_CH2     0x02
#define RP2_ADC_CH3     0x03
#define RP2_ADC_TEMP    0x04


/*! \brief RP2 ADC structure
* \param adc_channel      ADC Channel to be used
* \param vref             Reference Voltage
* \param scale_factor     Scale factor to be applied to the raw ADC value
* \param init_done        Initialization done flag
*/
typedef struct {
    uint8_t adc_channel;
    bool    init_done;  
} rp2_adc_t;


/*! \brief Initialize the internal RP2 ADC peripheral
    \param config       Pointer to the RP2 ADC configuration structure
    \return             true if initialization was successful, false otherwise
*/
bool rp2_adc_init(rp2_adc_t* config);


/*! \brief Change the ADC channel
    \param config        Pointer to the RP2 ADC configuration structure
    \param new_channel   New ADC channel to be used
    \return              true if channel change was successful, false otherwise
*/
bool rp2_change_channel(rp2_adc_t* config, uint8_t new_channel);


/*! \brief Read the raw ADC value from the specified channel
    \param config       Pointer to the RP2 ADC configuration structure
    \return             The raw ADC value as uint16_t but 12-bit are used
*/
uint16_t rp2_adc_read_raw(rp2_adc_t* config);


#endif

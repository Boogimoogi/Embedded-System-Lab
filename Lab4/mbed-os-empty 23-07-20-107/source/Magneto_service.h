#ifndef __BLE_MAGNETO__
#define __BLE_MAGNETO__

#include "ble/BLE.h"
#include "ble/Gap.h"
#include "ble/GattServer.h"

class MagnetoService {
public:
    const static uint16_t MAGNETO_UUID              = 0xA000;
    const static uint16_t MAGNETO_INT_UUIDx = 0xA001;
    const static uint16_t MAGNETO_INT_UUIDy = 0xA002;
    const static uint16_t MAGNETO_INT_UUIDz= 0xA003;

    MagnetoService(BLE &_ble, int magneto_data[3]) :
        ble(_ble), magneto_intensity_x(MAGNETO_INT_UUIDx, magneto_data),magneto_intensity_y(MAGNETO_INT_UUIDy, magneto_data),magneto_intensity_z(MAGNETO_INT_UUIDz, magneto_data)
    {
        GattCharacteristic *charTable[] = {&magneto_intensity_x,&magneto_intensity_y,&magneto_intensity_z};
        GattService         magnetoService(MagnetoService::MAGNETO_UUID, charTable, 3);
        ble.gattServer().addService(magnetoService);
    }

    void updateMagnetoIntensity(int magneto_data[3]) {
        ble_error_t err;
        int a;
        int b;
        int c;
        a=magneto_data[0];
        b=magneto_data[1];
        c=magneto_data[2];
        printf("%d  %d  %d\n",a,b,c);
        ble.gattServer().write(magneto_intensity_x.getValueHandle(), (uint8_t*)&a, 4);
        ble.gattServer().write(magneto_intensity_y.getValueHandle(), (uint8_t*)&b, 4);
        ble.gattServer().write(magneto_intensity_z.getValueHandle(), (uint8_t*)&c, 4);


    }

private:
    BLE                              &ble;
    ReadOnlyGattCharacteristic<int>  magneto_intensity_x;
    ReadOnlyGattCharacteristic<int>  magneto_intensity_y;
    ReadOnlyGattCharacteristic<int>  magneto_intensity_z;
};

#endif /* #ifndef __BLE_BUTTON_SERVICE_H__ */

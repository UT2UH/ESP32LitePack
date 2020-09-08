#ifndef __M5LiteAXP192_H__
#define __M5LiteAXP192_H__

#include <I2C_AXP192.h>

class M5LiteAXP192 {
  public:
    void begin(bool disableLDO2 = false, bool disableLDO3 = false, bool disableRTC = false, bool disableDCDC1 = false, bool disableDCDC3 = false) {
      if (!enable) {
        return;
      }

      if (_board == lgfx::board_M5StackCore2) {
        // M5Stack Core2
        I2C_AXP192_InitDef initDef = {
          .EXTEN  = true,
          .BACKUP = true,
          .DCDC1  = 3350,
          .DCDC2  = 0,
          .DCDC3  = 2800,
          .LDO2   = 0,
          .LDO3   = 0,
          .GPIO0  = 2800,
          .GPIO1  = -1,
          .GPIO2  = -1,
          .GPIO3  = -1,
          .GPIO4  = -1,
        };
        //_axp192->begin(initDef);
      } else if (_board == lgfx::board_M5StickC || _board == lgfx::board_M5StickCPlus) {
        // M5StickC
        I2C_AXP192_InitDef initDef = {
          .EXTEN  = true,
          .BACKUP = true,
          .DCDC1  = disableDCDC1 ? -1 : 3300,
          .DCDC2  = 0,
          .DCDC3  = disableDCDC3 ? -1 : -1,
          .LDO2   = disableLDO2  ? -1 : 3000,
          .LDO3   = disableLDO3  ? -1 : 3000,
          .GPIO0  = disableRTC   ? -1 : 2800,
          .GPIO1  = -1,
          .GPIO2  = -1,
          .GPIO3  = -1,
          .GPIO4  = -1,
        };
        _axp192->begin(initDef);
      }
    }

    void setAXP192(I2C_AXP192 *axp192) {
      _axp192 = axp192;
    }

    void setBoard(int board) {
      _board = board;
    }

    void ScreenBreath(uint8_t brightness) {
      if (!enable) {
        return;
      }

      if (brightness > 12) {
        brightness = 12;
      }
      _axp192->setLDO2(1800 + brightness * 100);
    }

    bool GetBatState() __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return true;
    }

    uint8_t GetInputPowerStatus() __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint8_t GetBatteryChargingStatus() __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }

    void DisableAllIRQ(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void ClearAllIRQ(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void EnablePressIRQ(bool short_press, bool long_press) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void GetPressIRQ(bool *short_press, bool* long_press) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void ClearPressIRQ(bool short_press, bool long_press) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }

    void EnableCoulombcounter(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void DisableCoulombcounter(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void StopCoulombcounter(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void ClearCoulombcounter(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    uint32_t GetCoulombchargeData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint32_t GetCoulombdischargeData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    float GetCoulombData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }

    uint16_t GetVbatData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetIchargeData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetIdischargeData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetTempData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint32_t GetPowerbatData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetVinData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetIinData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetVusbinData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetIusbinData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint16_t GetVapsData(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint8_t GetBtnPress(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }

    void SetSleep(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void DeepSleep(uint64_t time_in_us = 0) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void LightSleep(uint64_t time_in_us = 0) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }

    uint8_t GetWarningLeve(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }

    void SetChargeVoltage(uint8_t) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetChargeCurrent(uint8_t) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetVOff(uint8_t voltage) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }

    float GetBatVoltage() {
      if (!enable) {
        return 0;
      }
      return _axp192->getBatteryVoltage() / 1000.0;
    }
    float GetBatCurrent() {
      if (!enable) {
        return 0;
      }
      return _axp192->getBatteryChargeCurrent() - _axp192->getBatteryDischargeCurrent();
    }
    float GetVinVoltage() {
      if (!enable) {
        return 0;
      }
      if (_board == lgfx::board_M5StackCore2) {
        return _axp192->getVbusVoltage() / 1000.0;
      } else {
        return _axp192->getAcinVolatge() / 1000.0;
      }
    }
    float GetVinCurrent() {
      if (!enable) {
        return 0;
      }
      if (_board == lgfx::board_M5StackCore2) {
        return _axp192->getVbusCurrent();
      } else {
        return _axp192->getAcinCurrent();
      }
    }
    float GetVBusVoltage() {
      if (!enable) {
        return 0;
      }
      if (_board == lgfx::board_M5StackCore2) {
        return _axp192->getAcinVolatge() / 1000.0;
      } else {
        return _axp192->getVbusVoltage() / 1000.0;
      }
    }
    float GetVBusCurrent() {
      if (!enable) {
        return 0;
      }
      if (_board == lgfx::board_M5StackCore2) {
        return _axp192->getAcinCurrent();
      } else {
        return _axp192->getVbusCurrent();
      }
    }
    float GetTempInAXP192() {
      if (!enable) {
        return 0;
      }
      return _axp192->getInternalTemperature();
    }
    float GetBatPower() {
      if (!enable) {
        return 0;
      }
      return _axp192->getBatteryPower();
    }
    float GetBatChargeCurrent() {
      if (!enable) {
        return 0;
      }
      return _axp192->getBatteryChargeCurrent();
    }
    float GetAPSVoltage() {
      if (!enable) {
        return 0;
      }
      return _axp192->getApsVoltage() / 1000.0;
    }
    float GetBatCoulombInput() __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    float GetBatCoulombOut() __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    uint8_t GetWarningLevel(void) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
      return 0;
    }
    void SetCoulombClear()  __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetLDO2(bool State) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetLDO3(bool State) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetGPIO0(bool State) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetAdcState(bool State) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void SetAdcRate(uint8_t rate) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }

    void PowerOff() {
      if (!enable) {
        return;
      }
      _axp192->powerOff();
    }

    void Read6BytesStorage(uint8_t *bufPtr) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }
    void Write6BytesStorage(uint8_t *bufPtr) __attribute__((deprecated)) {
      // TODO
      ESP_LOGE("AXP192", "Not Support");
    }

    int enable = 0;

  private:
    I2C_AXP192 *_axp192;
    int _board;
};

#endif
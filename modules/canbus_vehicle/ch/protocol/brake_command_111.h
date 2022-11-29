/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "modules/canbus/vehicle/ch/proto/ch.pb.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ch {

class Brakecommand111 : public ::apollo::drivers::canbus::ProtocolData<
                            ::apollo::canbus::Ch> {
 public:
  static const int32_t ID;

  Brakecommand111();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': 'brake pedal enable bit(Command)',
  // 'enum': {0: 'BRAKE_PEDAL_EN_CTRL_DISABLE', 1:
  // 'BRAKE_PEDAL_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name':
  // 'BRAKE_PEDAL_EN_CTRL', 'offset': 0.0, 'order': 'intel', 'physical_range':
  // '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brakecommand111* set_brake_pedal_en_ctrl(
      Brake_command_111::Brake_pedal_en_ctrlType brake_pedal_en_ctrl);

  // config detail: {'bit': 8, 'description': 'Percentage of brake
  // pedal(Command)', 'is_signed_var': False, 'len': 8, 'name':
  // 'BRAKE_PEDAL_CMD', 'offset': 0.0, 'order': 'intel', 'physical_range':
  // '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  Brakecommand111* set_brake_pedal_cmd(int brake_pedal_cmd);

 private:
  // config detail: {'bit': 0, 'description': 'brake pedal enable bit(Command)',
  // 'enum': {0: 'BRAKE_PEDAL_EN_CTRL_DISABLE', 1:
  // 'BRAKE_PEDAL_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 8, 'name':
  // 'BRAKE_PEDAL_EN_CTRL', 'offset': 0.0, 'order': 'intel', 'physical_range':
  // '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_brake_pedal_en_ctrl(
      uint8_t* data,
      Brake_command_111::Brake_pedal_en_ctrlType brake_pedal_en_ctrl);

  // config detail: {'bit': 8, 'description': 'Percentage of brake
  // pedal(Command)', 'is_signed_var': False, 'len': 8, 'name':
  // 'BRAKE_PEDAL_CMD', 'offset': 0.0, 'order': 'intel', 'physical_range':
  // '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  void set_p_brake_pedal_cmd(uint8_t* data, int brake_pedal_cmd);

 private:
  Brake_command_111::Brake_pedal_en_ctrlType brake_pedal_en_ctrl_;
  int brake_pedal_cmd_;
};

}  // namespace ch
}  // namespace canbus
}  // namespace apollo

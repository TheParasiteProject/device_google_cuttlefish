/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#include <vector>

#include "host/libs/vm_manager/vm_manager.h"

#include "common/libs/fs/shared_fd.h"

namespace cuttlefish {
namespace vm_manager {

// Starts a guest VM using the qemu command directly. It requires the host
// package to support the qemu-cli capability.
class QemuManager : public VmManager {
 public:
  static std::string name() { return "qemu_cli"; }

  QemuManager(Arch arch) : VmManager(arch) {}
  virtual ~QemuManager() = default;

  bool IsSupported() override;
  std::vector<std::string> ConfigureGpuMode(const std::string&) override;
  std::vector<std::string> ConfigureBootDevices(int num_disks) override;

  std::vector<cuttlefish::Command> StartCommands(
      const CuttlefishConfig& config) override;
};

} // namespace vm_manager
} // namespace cuttlefish


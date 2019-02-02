#pragma once

#include <frc/commands/Command.h>
#include <Subsystems/LimitSwitches.h>

class TestCommand : public frc::Command {
 public:
  TestCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
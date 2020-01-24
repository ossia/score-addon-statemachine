#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <Process/Process.hpp>

#include <statemachine/Metadata.hpp>

namespace statemachine
{
class Model final : public Process::ProcessModel
{
  SCORE_SERIALIZE_FRIENDS
  PROCESS_METADATA_IMPL(statemachine::Model)
  W_OBJECT(Model)

public:
  Model(
      const TimeVal& duration, const Id<Process::ProcessModel>& id,
      QObject* parent);

  template <typename Impl>
  Model(Impl& vis, QObject* parent) : Process::ProcessModel{vis, parent}
  {
    vis.writeTo(*this);
  }

  ~Model() override;

private:
  QString prettyName() const noexcept override;
  void startExecution() override;
  void stopExecution() override;
  void reset() override;

  void setDurationAndScale(const TimeVal& newDuration) noexcept override;
  void setDurationAndGrow(const TimeVal& newDuration) noexcept override;
  void setDurationAndShrink(const TimeVal& newDuration) noexcept override;
};

using ProcessFactory = Process::ProcessFactory_T<statemachine::Model>;
}

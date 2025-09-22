#include "game.hpp"
#include <stdexcept>

namespace RPS {
  constexpr GameAction convertRawActionToGame(RawAction raw) {
    if (raw >= gameActions.size())
      throw std::runtime_error("Unable to convert invalid raw action");

    return gameActions[raw];
  }
}
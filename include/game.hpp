#ifndef RPS_GAME_HPP_
#define RPS_GAME_HPP_

#include <cstdint>
#include <array>

namespace RPS {
  using RawAction = std::uint8_t;
  enum class GameAction : std::uint8_t {
    ROCK = 0x0,
    PAPER = 0x1,
    SCISSORS = 0x2
  };

  inline constexpr std::array<GameAction, 3> gameActions {
    GameAction::ROCK,
    GameAction::PAPER,
    GameAction::SCISSORS
  };

  [[nodiscard]]
  constexpr GameAction convertRawActionToGame(RawAction raw);
}


#endif
- Layout
  Vertices consisting of roads and sidewalks were defined as specified in the assignment. Roads and lanes were drawn using vertex and fragment shaders.

- Vehicles
  The creation methods for cars and trucks were determined.

- Shaders
  Separate fragment and vertex shaders were created for the Agent, Coin, Vehicle, and Layout.
  !! In main.cpp, these shaders were passed as parameters by providing their absolute paths.
  This needs to be handled carefully; otherwise, only a white frame appears.

- Game
  The Game class is responsible for structuring all in-game actions.
  The most fundamental base class used was GameObject.

- Coin
  The formation of coins, which contribute extra points to the score, was defined.

- Agent
  The creation, appearance, and color of the agent were configured.
# LilithPort
LilithPort is a UDP multiplayer/netplay program for 2D Fighter Maker games. It includes chat and makes accommodations for players who cannot forward their ports. LilithPort is based off MT Special Edition, which is in turn based off LunaPort.

This program was *not* made with Enterbrain's permission. It was ultimately made by reverse engineering the 2D Fighter Maker code. More so, my translation/continuation of LilithPort was not made with the original LilithPort developer's permission. If he ever decides to pick this back up or make changes to the code, I will comply.

LilithPort requires .NET Framework 3.5.

## Games
Any game that uses 2D Fighter Maker (95/2002) will work. LilithPort is also backwards compatible with servers that use MTSP.
 - [Pokémon Type: Wild](http://oneweakness.com/pokemon-type-wild.html)
 - [Vanguard Princess](http://wiki.mizuumi.net/w/Vanguard_Princess/Netplay)
 - [WonderfulWorld](http://www55.atwiki.jp/ainefill_oinusama/pages/111.html)
 - and many more...
 
## Public Servers
Currently, no servers are being advertised for general use. Please visit your game's website for multiplayer information.

## Instructions
Sorry for everyone who has been waiting for so long for proper instructions on how to use LilithPort.

When you start LilithPort, a Welcome menu appears. There are 4 main modes of operation:
- **Free Play** - just play locally and configure options. To go to Free Play mode, just disconnect from a server (`Commands > Leave`) or press `Cancel` on the Welcome dialog.
- **Client** - connect to a server without match hosting capabilities. Useful if you cannot forward ports on your network.
- **Host** - connect to a server with match hosting capabilities.
  - *Listen port* - port used for hosting matches
- **Server** - host matches and create a lobby.
  - *Listen port* - port used for hosting server (default is 7500).

On the destination name, you can also enter the port separated by a colon (:) such as `MyServer:7500`.

### Special server modes
You can prepend a special symbol on your server name to activate some special behaviors:
 - `+` - mixed server mode. Random versus is disabled.
 - `@` - match server. Chat is disabled, and changing the user description to circumvent this is also disabled.
 - `#` - anonymous ("nora") server. Chat is disabled, and all players (except the host) are invisible. In order to play against someone, you must right-click the player list.

### IP conversion
Converting your IP to a string can yield some security benefits as your IP address is hidden from plain sight. When you convert an IP address, there are two results: a LilithPort-compatible conversion and an MTSP-compatible conversion. Both are supported by LilithPort. The main difference is that LilithPort uses Base64 to encode your IP address, while MTSP uses a cipher that uses a mix of Japanese kana and ASCII.
For example, `127.0.0.1` turns into `MTY3NzczNDM=` (LilithPort) and `uちたぐて` (MTSP).

### Player list
Each player will have a different text color based on their current mode (server, host, or client) and a different background color based on their status (in match, spectating, or resting).

Left-click to select a player; right-clicking alone won't select.
Double-click behavior depends on the target:
 - Yourself: toggle break state, stop spectating/match
 - Another player: obtain state, send ping
 - Other: toggle player list display
 
### Resting
When resting, people will not be able to challenge you to a match. However, you can still spectate while resting.

## Options
Profiles are available in case you are playing multiple 2D Fighter Maker games and you need to tweak specific options for each game.
### Basic
Game executable path: path to a valid 2DFM EXE file. You can also drag and drop the EXE file onto the Options dialog.
By checking `Name replay files automatically`, LilithPort will create a folder for each game to save replays in.
### Sounds
You can assign a sound to any event. You can also "stalk" specific keywords so that you are alerted when they are mentioned in chat.
### Game
 - Max stages: number of stages used by the game. Set this to 1 if unsure. If this number is higher than the real number of stages in the game, the game will crash.
 - Random stage: if 0, the stage will be selected at random; if the value is greater than the maximum number of stages, it will cycle through stages.
 - Number of rounds: Number of rounds in match. Ignored in FM95 games.
 - Match timer: exactly what it says on the tin.
 - Delay: if you've ever played a fighting game that uses GGPO, you'll know what this does. This only works in single player to simulate frame delay.
 - Random number: not quite sure what this does, to be honest. According to the translated readme, it shows a random number used in the last 100 frames.
 - Replay compression: compresses the replay file. Always keep enabled unless debugging.
 - HP carryover: the HP of the player who won the round is carried over on the next round. Slightly experimental.

### Volume
This controls the volume in game.
 - BGM: background music volume
 - SE: all other audio files
 - Software synthesizer/MIDI: depends on environment. Newer operating systems have this slider disabled.

## Spectating
You can spectate matches until about 5 seconds after they have begun.
If a player is currently playing back a replay, you can spectate the replay. 
The number of spectators allowed in your match is equal to the maximum number of connections/players. If you stop accepting spectators during a match, all current spectators are kicked.
You can also spectate spectators (relay mode) to lessen the burden of a player.

## Chat
### Announcements
If you are a server owner, you can use `Ctrl+Enter` to send a notice to all players that looks similar to the MOTD. Underscores are automatically converted into new lines.

For instance, `The server will be shutting down at _ 5 PM today` will be converted to the following:
```
The server will be shutting down at
5 PM today
```
### Commands
Commands are prefixed with a slash (`/`). You can use `/help` to view an up-to-date list of commands.

## Frame delay
The largest calculated frame delay applies to both players in the match. If Player 2 has his frame delay set to Auto, the frame delay is determined by the ping using the following formula:

`Delay = (Ping / 10) + 2`
where the maximum frame delay is 12.

Player 2 calculates the delay and passes it to Player 1. If Player 1 has a greater frame delay (as set either manually or determined with ping), that larger delay will be sent back to Player 2.

## Easy Game Path Changing
By dragging and dropping your game executable on the main window, the game path is automatically changed without having to enter the options menu. If a profile was configured for that specific game, then that profile will automatically be opened as well.

## Joystick Warning
If you are playing an FM95 game, the joystick is disabled due to compatibility reasons. Please use JoyToKey or [AntiMicro](https://github.com/Ryochan7/antimicro/releases).

In addition, there is a massive performance penalty for turning on joystick support in 2DFM in most cases. 
The reason is that 2DFM will silently error out when a joystick is expected but is not detected. In order to mitigate this, please have at least two controllers plugged in.

## Dedicated Server
A dedicated server is coming in the very distant future. In the meantime, you can pass the `-s <port>` command line argument to LilithPort to start server mode immediately and close silently on exception.

#Arena Spectator

####About
Arena Spectator gives you the
oportunity to spectate players when
they are in arena.You can spectate a 
2vs2 / 3vs3 / 5vs5 / Specific Player arena.


####Installation

Available as:
- Direct merge: https://github.com/Flameshot/TrinityCore/tree/Arena-Spectator
- Diff/Patch: http://flameshot.tk/ipbdownload/Arena-Spectator.diff

Using direct merge:
- open git bash to source location
- do `git remote add flameshot https://github.com/Flameshot/TrinityCore.git`
- do `git pull flameshot arena-spectator`
- use cmake and compile

Using diff:
- download the diff by __right clicking__ the link and select __Save link as__
- place the downloaded `arena-spectator.diff` to the source root folder
- open git bash to source location
- do `git apply arena-spectator.diff`
- use cmake and compile

After compiling:
- Navigate to `\src\server\scripts\Custom\ArenaSpectator\sql\`
- Run `Arena Spectator NPC.sql` to your world database
- Run `rbac_permissions.sql` to your auth database
- Run `rbac_linked_permissions.sql` to your auth database
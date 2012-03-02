SET @SPELL_HORDE := 56618;
SET @SPELL_ALLIANCE := 56617;

SET @AREA_SUNKEN_RING := 4538;
SET @AREA_BROKEN_TEMPLE := 4539;
SET @AREA_W_WORKSHOP := 4611;
SET @AREA_E_WORKSHOP := 4612;

DELETE FROM `spell_area` WHERE `spell` IN (@SPELL_HORDE, @SPELL_ALLIANCE);
INSERT INTO `spell_area` (`spell`,`area`,`autocast`) VALUES
(@SPELL_HORDE, @AREA_SUNKEN_RING, 1),
(@SPELL_ALLIANCE, @AREA_SUNKEN_RING, 1),
(@SPELL_HORDE, @AREA_BROKEN_TEMPLE, 1),
(@SPELL_ALLIANCE, @AREA_BROKEN_TEMPLE, 1),
(@SPELL_HORDE, @AREA_W_WORKSHOP, 1),
(@SPELL_ALLIANCE, @AREA_W_WORKSHOP, 1),
(@SPELL_HORDE, @AREA_E_WORKSHOP, 1),
(@SPELL_ALLIANCE, @AREA_E_WORKSHOP, 1);

/* 

Spell 56617 "Alliance Controls Factory Phase Shift" Adds Phase 32
Spell 56618 "Horde Controls Factory Phase Shift" Adds Phase 16

Spell 55773 "Horde Control Phase Shift" Adds Phase 64
Spell 55774 "Alliance Control Phase Shift" Adds Phase 128

Spell 58045 "Essence of Wintergrasp" Adds Phase 256

Spell 37795 "Recruit" Gained when joining WG battle

Spell 74411 "Battleground - Dampening"  Gained when joining WG battle

Spell 61409 "Build Siege Vehicle (Force)" is cast by npc 30400 "Goblin Mechanic <Demolisher Engineer>" on player
Spell 56664 "Build Catapult (Force)" is cast by npc 30499 "Gnomish Engineer <Demolisher Engineer>" on player
Spell 56662 "Build Siege Vehicle (Force)" is cast by npc 30499 "Gnomish Engineer <Demolisher Engineer>" on player

Spell 50398 "Riding Trainer Advertisement" is cast by npc 30869 "Arzo Safeflight <Flight Master>" on self

Wintergrasp Vehicle On spawn entries: 28312,27881,28094,32627
set x,y,z,o to nearest trigger entry: 23472
make player cast 60968 on vehicle
aura 14267 on self if player is horde
aura 14268 on self if player is alliance

Spells cast on vehicle as auras... or something (PET_SPELLS cooldowns):
61178 (Grab Passenger) (Catapult, Siege Engine... NOT tower cannons)
56866 (-Unknown-) (Catapult, Siege Engine.... NOT tower cannons)
14268 (Alliance Flag) (Catapult, Siege Engine... NOT tower cannons)
14267 (Horde Flag)

*/

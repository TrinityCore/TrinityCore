-- Set Sheath Melee handled in core
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15938 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16378 AND `source_type` = 0 AND `id` IN (2,6);
UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 16378 AND `source_type` = 0 AND `id` IN (1,5);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26414,27224,27225,27377,27564,27749) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26414,0,0,0,0,0,100,0,0,0,4000,6000,0,11,46982,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Runic Lightning Gunner - In Combat CMC - Cast 'Lightning Gun Shot'"),
(26414,0,1,2,8,0,100,1,48046,0,0,0,0,11,48047,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Spellhit 'Use Camera' - Cast 'Iron Dwarf Snapshot Credit' (No Repeat)"),
(26414,0,2,0,61,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Runic Lightning Gunner - On Spellhit 'Use Camera' - Despawn Instant (No Repeat)"),

(27224,0,0,0,0,0,100,0,0,0,2300,3900,0,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Forgotten Knight - In Combat CMC - Cast 'Throw'"),
(27224,0,1,0,23,0,100,0,48143,0,2000,2000,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Knight - On Has Aura 'Forgotten Aura' - Cast 'Forgotten Aura'"),
(27224,0,2,3,8,0,100,0,48882,0,0,0,0,3,27465,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Knight - On Spellhit 'Spirits Redeemed' - Update Template To 'Forgotten Soul'"),
(27224,0,3,0,61,0,100,0,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Knight - On Link - Die"),
(27224,0,4,5,62,0,100,0,9544,0,0,0,0,85,48831,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forgotten Knight - On Gossip Option 0 Selected - Invoker Cast 'Forgotten Knight Credit'"),
(27224,0,5,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forgotten Knight - On Gossip Option 0 Selected - Close Gossip"),

(27225,0,0,0,0,0,100,0,0,0,2300,3900,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Forgotten Rifleman - In Combat CMC - Cast 'Shoot'"),
(27225,0,1,0,0,0,100,0,9000,12000,9000,14000,0,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Forgotten Rifleman - In Combat - Cast 'Concussive Shot'"),
(27225,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Forgotten Rifleman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(27225,0,3,0,23,0,100,0,48143,0,2000,2000,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Rifleman - On Has Aura 'Forgotten Aura' - Cast 'Forgotten Aura'"),
(27225,0,4,5,8,0,100,0,48882,0,0,0,0,3,27465,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Rifleman - On Spellhit 'Spirits Redeemed' - Update Template To 'Forgotten Soul'"),
(27225,0,5,0,61,0,100,0,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Forgotten Rifleman - On Link - Die"),
(27225,0,6,7,62,0,100,0,9543,0,0,0,0,85,48830,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forgotten Rifleman - On Gossip Option 0 Selected - Invoker Cast 'Forgotten Rifleman Credit'"),
(27225,0,7,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Forgotten Rifleman - On Gossip Option 0 Selected - Close Gossip"),

(27377,0,0,0,0,0,100,0,0,0,2300,3900,0,11,50512,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat CMC - Cast 'Shoot'"),
(27377,0,1,0,0,0,100,0,9000,12000,12000,15000,0,11,52813,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat - Cast 'Multi-Shot'"),
(27377,0,2,0,0,0,100,0,8000,13000,9000,15000,0,11,34829,0,0,0,0,0,6,0,0,0,0,0,0,0,0,"Thane Torvald Eriksson - In Combat - Cast 'Arcane Shot'"),
(27377,0,3,0,9,0,100,0,10,70,15000,20000,0,11,56843,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Within 10-70 Range - Cast 'Volley'"),
(27377,0,4,0,2,0,100,0,0,30,15000,19000,0,11,57057,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Thane Torvald Eriksson - Between 0-30% Health - Cast 'Torvald's Deterrence'"),

(27564,0,0,0,1,0,100,0,0,5000,0,10000,0,11,49329,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Alliance Conscript - Out of Combat - Cast 'Summon Frigid Ghoul Attacker'"),
(27564,0,1,0,0,0,100,0,0,0,2300,3900,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Conscript - In Combat CMC - Cast 'Shoot'"),
(27564,0,2,0,9,0,100,0,0,5,5000,9000,0,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Alliance Conscript - Within 0-5 Range - Cast 'Heroic Strike'"),

(27749,0,0,0,1,0,100,0,0,5000,0,10000,0,11,49329,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Horde Conscript - Out of Combat - Cast 'Summon Frigid Ghoul Attacker'"),
(27749,0,1,0,0,0,100,0,0,0,2300,3900,0,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Conscript - In Combat CMC - Cast 'Shoot'"),
(27749,0,2,0,9,0,100,0,0,5,7000,9000,0,11,29426,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Horde Conscript - Within 0-5 Range - Cast 'Heroic Strike'");

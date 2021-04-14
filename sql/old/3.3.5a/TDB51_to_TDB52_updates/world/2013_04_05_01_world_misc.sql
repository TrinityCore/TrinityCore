SET @LAFOO := 28120;
SET @MOODLE := 28122;
SET @JALOOT := 28121;
SET @CHICKENESCAPEE := 28161;
SET @GOREGEK := 28214;
SET @DAJIK := 28215;
SET @ZEPIK := 28216;
SET @MISTWHISPERLIGHTNINGCLOUD := 28253;
SET @MISTWHISPERLIGHTNINGTARGET := 28254;
SET @GLINTINGDIRT := 28362;
SET @RHUNOK := 28416;
SET @TORMENTOR := 28575;
SET @SCAREDSOFTKNUCKLE := 50979;
SET @LIGHTNING := 51172;
SET @FRENZYAURA := 51234;
SET @MISTWHISPERAURA := 51239; 
SET @DIGGINGFORTEASURE := 51405;
SET @TREASUREPING:= 51420;
SET @THROWSPEAR := 51603;
SET @CHAINS1 := 51606;
SET @CHAINS2 := 51607;
SET @RAINSPEAKERAURA := 51639;
SET @SPEARBORNAURA := 51642;
SET @MOSSWALKERAURA := 51644;
SET @SKYREACHPILLARAURA:= 51645;
SET @SAPPHIREHIVEAURA := 51651;
SET @WOLVARPING := 51791;
SET @GORLOCPING := 51794;
SET @CHICKENLOCATIONPING := 51843;
SET @SCAREDCHICKEN := 51846;
SET @DESSAWNRETAINER := 53163;

DELETE FROM `creature_text` WHERE `entry`=@TORMENTOR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@TORMENTOR,0,0,'Filthy $R intruder. DIE!',12,0,100,0,0,0,'Rhunok''s Tormentor'),
(@TORMENTOR,0,1,'If Rhunok regains his strength, we all die!',12,0,100,0,0,0,'Rhunok''s Tormentor'),
(@TORMENTOR,0,2,'There are intruders about. Slay them before they ruin everything!',12,0,100,0,0,0,'Rhunok''s Tormentor'),
(@TORMENTOR,0,3,'The bear god must be kept enfeebled so that the prophet can finish the ritual.',12,0,100,0,0,0,'Rhunok''s Tormentor'),
(@TORMENTOR,0,4,'Keep him weak!',12,0,100,0,0,0,'Rhunok''s Tormentor');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@TORMENTOR;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@TORMENTOR;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-113481,-113482,-113483,-113558,@TORMENTOR) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TORMENTOR,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rhunok''s Tormentor - On aggro - Say line'),
(@TORMENTOR,0,1,0,0,0,100,0,3000,8000,10000,20000,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rhunok''s Tormentor - On update IC - Spellcast Throw'),
(@TORMENTOR,0,2,0,0,0,100,0,5000,30000,30000,35000,11,54526,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rhunok''s Tormentor - On update IC - Spellcast Torment'),
(@TORMENTOR,0,3,0,1,0,100,0,5000,30000,30000,40000,11,@THROWSPEAR,0,0,0,0,0,10,95460,@RHUNOK,0,0,0,0,0, 'Rhunok''s Tormentor - On update OOC - Spellcast Throw Spear'),

(-113481,0,0,0,1,0,100,0,0,0,5000,5000,11,@CHAINS1,0,0,0,0,0,10,95460,@RHUNOK,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC - Spellcast Rhunok''s Chains'),
(-113482,0,0,0,1,0,100,0,0,0,5000,5000,11,@CHAINS2,0,0,0,0,0,10,95460,@RHUNOK,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC - Spellcast Rhunok''s Chains'),
(-113483,0,0,0,1,0,100,0,0,0,5000,5000,11,@CHAINS1,0,0,0,0,0,10,95460,@RHUNOK,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC - Spellcast Rhunok''s Chains'),
(-113558,0,0,0,1,0,100,0,0,0,5000,5000,11,@CHAINS2,0,0,0,0,0,10,95460,@RHUNOK,0,0,0,0,0, 'ELM General Purpose Bunny - On update OOC - Spellcast Rhunok''s Chains');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@THROWSPEAR,@CHAINS1,@CHAINS2,@LIGHTNING,@SCAREDSOFTKNUCKLE,@FRENZYAURA,@RAINSPEAKERAURA,@WOLVARPING,@GORLOCPING,@DESSAWNRETAINER,@CHICKENLOCATIONPING,@TREASUREPING,@DIGGINGFORTEASURE,@MOSSWALKERAURA,@SPEARBORNAURA,@MISTWHISPERAURA,@SAPPHIREHIVEAURA,@SCAREDCHICKEN,@SKYREACHPILLARAURA);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@LIGHTNING,0,31,3,@MISTWHISPERLIGHTNINGTARGET,0,0,0, '', 'Cloud to Lightning hits Mistwhisper Lightning Target'),
(13,1,@LIGHTNING,1,31,3,@MISTWHISPERLIGHTNINGCLOUD,0,0,0, '', 'Cloud to Lightning hits Mistwhisper Lightning Cloud'),
(13,1,@FRENZYAURA,0,31,3,@GOREGEK,0,0,0,'','Spell Frenzyheart Hill Aura targets Goregek the Bristlepine Hunter'),
(13,1,@FRENZYAURA,1,31,3,@DAJIK,0,0,0,'','Spell Frenzyheart Hill Aura targets Dajik the Wasp Hunter'),
(13,1,@FRENZYAURA,2,31,3,@ZEPIK,0,0,0,'','Spell Frenzyheart Hill Aura targets Zepik the Gorloc Hunter'),
(13,1,@RAINSPEAKERAURA,0,31,3,@LAFOO,0,0,0,'','Spell Rainspeaker Canopy Aura targets Lafoo'),
(13,1,@RAINSPEAKERAURA,1,31,3,@MOODLE,0,0,0,'','Spell Rainspeaker Canopy Aura targets Jaloot'),
(13,1,@RAINSPEAKERAURA,2,31,3,@JALOOT,0,0,0,'','Spell Rainspeaker Canopy Aura targets Moodle'),
(13,1,@WOLVARPING,0,31,3,@GOREGEK,0,0,0,'','Spell Wolvar Location Ping targets Goregek the Bristlepine Hunter'),
(13,1,@WOLVARPING,1,31,3,@DAJIK,0,0,0,'','Spell Wolvar Location Ping targets Dajik the Wasp Hunter'),
(13,1,@WOLVARPING,2,31,3,@ZEPIK,0,0,0,'','Spell Wolvar Location Ping targets Zepik the Gorloc Hunter'),
(13,1,@GORLOCPING,0,31,3,@LAFOO,0,0,0,'','Spell Gorloc Location Ping targets Lafoo'),
(13,1,@GORLOCPING,1,31,3,@JALOOT,0,0,0,'','Spell Gorloc Location Ping targets Jaloot'),
(13,1,@GORLOCPING,2,31,3,@MOODLE,0,0,0,'','Spell Gorloc Location Ping targets Moodle'),
(13,1,@DESSAWNRETAINER,0,31,3,@LAFOO,0,0,0,'','Spell Dessawn Retainer targets Lafoo'),
(13,1,@DESSAWNRETAINER,1,31,3,@DAJIK,0,0,0,'','Spell Dessawn Retainer targets Dajik the Wasp Hunter'),
(13,1,@DESSAWNRETAINER,2,31,3,@ZEPIK,0,0,0,'','Spell Dessawn Retainer targets  Zepik the Gorloc Hunter'),
(13,1,@DESSAWNRETAINER,3,31,3,@JALOOT,0,0,0,'','Spell Dessawn Retainer targets Jaloot '),
(13,1,@DESSAWNRETAINER,4,31,3,@MOODLE,0,0,0,'','Spell Dessawn Retainer targets Moodle'),
(13,1,@DESSAWNRETAINER,5,31,3,@GOREGEK,0,0,0,'','Spell Dessawn Retainer targets  Goregek'),
(13,1,@TREASUREPING,0,31,3,@LAFOO,0,0,0,'','Spell Dessawn Retainer targets Lafoo'),
(13,1,@TREASUREPING,1,31,3,@JALOOT,0,0,0,'','Spell Dessawn Retainer targets Jaloot '),
(13,1,@TREASUREPING,2,31,3,@MOODLE,0,0,0,'','Spell Dessawn Retainer targets Moodle'),
(13,1,@CHICKENLOCATIONPING,0,31,3,@GOREGEK,0,0,0,'','Spell chicken ping targets Goregek'),
(13,1,@CHICKENLOCATIONPING,1,31,3,@DAJIK,0,0,0,'','Spell chicken ping targets Dajik '),
(13,1,@CHICKENLOCATIONPING,2,31,3,@ZEPIK,0,0,0,'','Spell chicken ping targets Zepik'),
(13,3,@SCAREDCHICKEN,0,31,3,@CHICKENESCAPEE,0,0,0,'','Scared Chicken targets only chicken escapee'),
(13,1,@MOSSWALKERAURA,0,31,3,@MOODLE,0,0,0,'','Mosswalker village aura targets moodle'),
(13,1,@SPEARBORNAURA,0,31,3,@JALOOT,0,0,0,'','spearborn encampment aura targets moodle'),
(13,1,@MISTWHISPERAURA,0,31,3,@ZEPIK,0,0,0,'','mistwhisper refuge aura targets zepik'),
(13,1,@SAPPHIREHIVEAURA,0,31,3,@DAJIK,0,0,0,'','sapphire hive aura targets dajik'),
(13,1,@THROWSPEAR,0,31,3,@RHUNOK,0,0,0,'','Spell Throw Spear targets Rhunok'),
(13,1,@CHAINS1,0,31,3,@RHUNOK,0,0,0,'','Spell Rhunok''s Chains targets Rhunok'),
(13,1,@CHAINS2,0,31,3,@RHUNOK,0,0,0,'','Spell Rhunok''s Chains targets Rhunok'),
(13,1,@SKYREACHPILLARAURA,0,31,3,@DAJIK,0,0,0,'','skyreach pillar aura targets dajik');

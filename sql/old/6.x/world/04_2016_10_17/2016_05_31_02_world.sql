-- DB/Profession: Added Enchanting trainer spells
SET @EnchantingLowLevel := 201124;
SET @EnchantingMidLevel := 201125;
SET @EnchantingHighLevel := 201126;

SET @EnchantingSkill := 333;

DELETE FROM `npc_trainer` WHERE `ID` IN
(@EnchantingLowLevel,@EnchantingMidLevel,@EnchantingHighLevel,
1317,3011,3345,3606,4213,4616,5157,5695,11072,11073,11074,
16160,16633,16725,18753,18773,19251,19252,26906,26980,26990,
28693,33583,33610,33633,33676,53410,65127,85914,86027);

INSERT INTO `npc_trainer` (`ID`,`SpellID`,`MoneyCost`,`ReqSkillLine`,`ReqSkillRank`,`ReqLevel`) VALUES

-- Enchanting-HighLevel --
(@EnchantingHighLevel,7411,10,@EnchantingSkill,0,5), -- Enchanting Rank 1
(@EnchantingHighLevel,14293,50,@EnchantingSkill,10,0), -- Lesser Magic Wand
(@EnchantingHighLevel,7420,50,@EnchantingSkill,15,0), -- Minor Health
(@EnchantingHighLevel,7426,100,@EnchantingSkill,40,0), -- Minor Absorbtion
(@EnchantingHighLevel,7412,500,@EnchantingSkill,50,10), -- Enchanting Rank 2
(@EnchantingHighLevel,7457,250,@EnchantingSkill,50,0), -- Minor Stamina
(@EnchantingHighLevel,7748,250,@EnchantingSkill,60,0), -- Lesser Health
(@EnchantingHighLevel,7771,200,@EnchantingSkill,70,0), -- Minor Protection
(@EnchantingHighLevel,14807,200,@EnchantingSkill,70,0), -- Greater Magic Wand
(@EnchantingHighLevel,7779,400,@EnchantingSkill,80,0), -- Minor Agility
(@EnchantingHighLevel,7788,500,@EnchantingSkill,90,0), -- Minor Striking
(@EnchantingHighLevel,7745,500,@EnchantingSkill,100,0), -- Minor Impact
(@EnchantingHighLevel,13378,600,@EnchantingSkill,105,0), -- Minor Stamina
(@EnchantingHighLevel,13421,800,@EnchantingSkill,115,0), -- Lesser Protection
(@EnchantingHighLevel,7857,1000,@EnchantingSkill,120,0), -- Health
(@EnchantingHighLevel,7413,5000,@EnchantingSkill,125,20), -- Enchanting Rank 3
(@EnchantingHighLevel,7863,1400,@EnchantingSkill,125,0), -- Minor Stamina
(@EnchantingHighLevel,13485,1500,@EnchantingSkill,130,0), -- Lesser Spirit
(@EnchantingHighLevel,13501,1500,@EnchantingSkill,130,0), -- Lesser Stamina
(@EnchantingHighLevel,13538,2500,@EnchantingSkill,140,0), -- Lesser Absorbtion
(@EnchantingHighLevel,13503,2000,@EnchantingSkill,140,0), -- Lesser Striking
(@EnchantingHighLevel,13529,2400,@EnchantingSkill,145,0), -- Lesser Impact
(@EnchantingHighLevel,13607,2400,@EnchantingSkill,145,0), -- Mana
(@EnchantingHighLevel,13622,2500,@EnchantingSkill,150,0), -- Lesser Intellect
(@EnchantingHighLevel,13626,2500,@EnchantingSkill,150,0), -- Minor Stats
(@EnchantingHighLevel,13635,2600,@EnchantingSkill,155,0), -- Defense
(@EnchantingHighLevel,13631,2600,@EnchantingSkill,155,0), -- Lesser Stamina
(@EnchantingHighLevel,11289,2600,@EnchantingSkill,155,0), -- Lesser Mystic Wand
(@EnchantingHighLevel,13640,2700,@EnchantingSkill,160,0), -- Greater Health
(@EnchantingHighLevel,13637,2800,@EnchantingSkill,160,0), -- Lesser Agility
(@EnchantingHighLevel,13642,2800,@EnchantingSkill,165,0), -- Spirit
(@EnchantingHighLevel,13646,2800,@EnchantingSkill,170,0), -- Lesser Dodge
(@EnchantingHighLevel,13644,2800,@EnchantingSkill,170,0), -- Lesser Stamina
(@EnchantingHighLevel,13648,2800,@EnchantingSkill,170,0), -- Stamina
(@EnchantingHighLevel,11290,3000,@EnchantingSkill,175,0), -- Greater Mystic Wand
(@EnchantingHighLevel,13659,3200,@EnchantingSkill,180,0), -- Spirit
(@EnchantingHighLevel,13661,3600,@EnchantingSkill,180,0), -- Strength
(@EnchantingHighLevel,13663,3800,@EnchantingSkill,185,0), -- Greater Mana
(@EnchantingHighLevel,13693,4000,@EnchantingSkill,195,0), -- Striking
(@EnchantingHighLevel,13920,50000,@EnchantingSkill,200,35), -- Enchanting Rank 4
(@EnchantingHighLevel,13695,4000,@EnchantingSkill,200,0), -- Impact
(@EnchantingHighLevel,13700,4000,@EnchantingSkill,200,0), -- Lesser Stats
(@EnchantingHighLevel,13746,4200,@EnchantingSkill,205,0), -- Greater Defense
(@EnchantingHighLevel,13815,4400,@EnchantingSkill,210,0), -- Agility
(@EnchantingHighLevel,13822,4400,@EnchantingSkill,210,0), -- Intellect
(@EnchantingHighLevel,13836,4600,@EnchantingSkill,215,0), -- Stamina
(@EnchantingHighLevel,13858,4800,@EnchantingSkill,220,0), -- Superior Health
(@EnchantingHighLevel,63746,5000,@EnchantingSkill,225,0), -- Lesser Accuracy
(@EnchantingHighLevel,13890,5000,@EnchantingSkill,225,0), -- Minor Speed
(@EnchantingHighLevel,13887,5000,@EnchantingSkill,225,0), -- Strength
(@EnchantingHighLevel,13905,5400,@EnchantingSkill,230,0), -- Greater Spirit
(@EnchantingHighLevel,13917,5400,@EnchantingSkill,230,0), -- Superior Mana
(@EnchantingHighLevel,13935,5800,@EnchantingSkill,235,0), -- Agility
(@EnchantingHighLevel,13937,6200,@EnchantingSkill,240,0), -- Greater Impact
(@EnchantingHighLevel,13939,6200,@EnchantingSkill,240,0), -- Greater Strength
(@EnchantingHighLevel,13943,6200,@EnchantingSkill,245,0), -- Greater Striking
(@EnchantingHighLevel,13941,6200,@EnchantingSkill,245,0), -- Stats
(@EnchantingHighLevel,12810,10000,@EnchantingSkill,250,0), -- Enchanted Leather
(@EnchantingHighLevel,12655,10000,@EnchantingSkill,250,0), -- Enchanted Thorium Bar
(@EnchantingHighLevel,13948,6500,@EnchantingSkill,250,0), -- Minor Haste
(@EnchantingHighLevel,20008,10000,@EnchantingSkill,255,0), -- Greater Intellect
(@EnchantingHighLevel,20012,10000,@EnchantingSkill,270,0), -- Greater Agility
(@EnchantingHighLevel,28029,100000,@EnchantingSkill,275,50), -- Enchanting Rank 5
(@EnchantingHighLevel,20016,15000,@EnchantingSkill,280,0), -- Vitality
(@EnchantingHighLevel,20028,15000,@EnchantingSkill,290,0), -- Major Mana
(@EnchantingHighLevel,20023,20000,@EnchantingSkill,295,0), -- Greater Agility
(@EnchantingHighLevel,20013,20000,@EnchantingSkill,295,0), -- Greater Strength
(@EnchantingHighLevel,42613,10000,@EnchantingSkill,300,0), -- Nexus Transformation
(@EnchantingHighLevel,34002,12500,@EnchantingSkill,300,0), -- Lesser Assault
(@EnchantingHighLevel,33991,20000,@EnchantingSkill,300,0), -- Restore Mana Prime
(@EnchantingHighLevel,33993,12500,@EnchantingSkill,305,0), -- Blasting
(@EnchantingHighLevel,27899,12500,@EnchantingSkill,305,0), -- Brawn
(@EnchantingHighLevel,34001,12500,@EnchantingSkill,305,0), -- Major Intellect
(@EnchantingHighLevel,33996,15000,@EnchantingSkill,310,0), -- Assault
(@EnchantingHighLevel,34004,15000,@EnchantingSkill,310,0), -- Greater Agility
(@EnchantingHighLevel,27944,15000,@EnchantingSkill,310,0), -- Lesser Dodge
(@EnchantingHighLevel,27961,15000,@EnchantingSkill,310,0), -- Major Armor
(@EnchantingHighLevel,27957,17500,@EnchantingSkill,315,0), -- Exceptional Health
(@EnchantingHighLevel,27905,12500,@EnchantingSkill,315,0), -- Stats
(@EnchantingHighLevel,33990,20000,@EnchantingSkill,320,0), -- Major Spirit
(@EnchantingHighLevel,28027,40000,@EnchantingSkill,325,0), -- Prismatic Sphere
(@EnchantingHighLevel,44383,25000,@EnchantingSkill,330,0), -- Resilience
(@EnchantingHighLevel,42615,40000,@EnchantingSkill,335,0), -- Small Prismatic Shard
(@EnchantingHighLevel,33995,25000,@EnchantingSkill,340,0), -- Major Strength
(@EnchantingHighLevel,51313,350000,@EnchantingSkill,350,65), -- Enchanting Rank 6
(@EnchantingHighLevel,28028,80000,@EnchantingSkill,350,0), -- Void Sphere
(@EnchantingHighLevel,27958,50000,@EnchantingSkill,350,0), -- Exceptional mana
(@EnchantingHighLevel,60609,50000,@EnchantingSkill,350,0), -- Speed
(@EnchantingHighLevel,60616,50000,@EnchantingSkill,360,0), -- Assault
(@EnchantingHighLevel,44592,50000,@EnchantingSkill,360,0), -- Exceptional Spellpower
(@EnchantingHighLevel,44623,50000,@EnchantingSkill,370,0), -- Super Stats
(@EnchantingHighLevel,44555,50000,@EnchantingSkill,375,0), -- Exceptional Intellect
(@EnchantingHighLevel,60606,50000,@EnchantingSkill,375,0), -- Assault
(@EnchantingHighLevel,44506,50000,@EnchantingSkill,375,0), -- Gatherer
(@EnchantingHighLevel,60621,80000,@EnchantingSkill,380,0), -- Greater Potency
(@EnchantingHighLevel,60623,90000,@EnchantingSkill,385,0), -- Icewalker
(@EnchantingHighLevel,62959,90000,@EnchantingSkill,385,0), -- Spellpower
(@EnchantingHighLevel,44528,90000,@EnchantingSkill,385,0), -- Greater Fortitude
(@EnchantingHighLevel,69412,50000,@EnchantingSkill,390,0), -- Abyssal Shatter
(@EnchantingHighLevel,44630,80000,@EnchantingSkill,390,0), -- Greater Savagery
(@EnchantingHighLevel,44582,100000,@EnchantingSkill,395,0), -- Minor Power
(@EnchantingHighLevel,44629,100000,@EnchantingSkill,395,0), -- Exceptional Spellpower
(@EnchantingHighLevel,44513,100000,@EnchantingSkill,395,0), -- Greater Assault
(@EnchantingHighLevel,60653,100000,@EnchantingSkill,395,0), -- Greater Intellect
(@EnchantingHighLevel,44635,100000,@EnchantingSkill,395,0), -- Greater Spellpower
(@EnchantingHighLevel,44492,100000,@EnchantingSkill,395,0), -- Mighty Health
(@EnchantingHighLevel,44500,100000,@EnchantingSkill,395,0), -- Superior Agility
(@EnchantingHighLevel,47766,100000,@EnchantingSkill,400,0), -- Greater Dodge
(@EnchantingHighLevel,44616,100000,@EnchantingSkill,400,0), -- Greater Stats
(@EnchantingHighLevel,44584,150000,@EnchantingSkill,405,0), -- Greater Vitality
(@EnchantingHighLevel,44484,150000,@EnchantingSkill,405,0), -- Haste
(@EnchantingHighLevel,44633,150000,@EnchantingSkill,410,0), -- Exceptional Agility
(@EnchantingHighLevel,44510,150000,@EnchantingSkill,410,0), -- Exceptional Spirit
(@EnchantingHighLevel,44508,150000,@EnchantingSkill,410,0), -- Greater Spirit
(@EnchantingHighLevel,44488,150000,@EnchantingSkill,410,0), -- Precision
(@EnchantingHighLevel,44598,150000,@EnchantingSkill,415,0), -- Haste
(@EnchantingHighLevel,44529,150000,@EnchantingSkill,415,0), -- Major Agility
(@EnchantingHighLevel,44589,150000,@EnchantingSkill,415,0), -- Superior Agility
(@EnchantingHighLevel,44489,150000,@EnchantingSkill,420,0), -- Dodge
(@EnchantingHighLevel,44509,150000,@EnchantingSkill,420,0), -- Greater Mana Restoration
(@EnchantingHighLevel,60663,150000,@EnchantingSkill,420,0), -- Major Agility
(@EnchantingHighLevel,44593,150000,@EnchantingSkill,420,0), -- Major Spirit
(@EnchantingHighLevel,74258,500000,@EnchantingSkill,425,75), -- Enchanting Rank 7
(@EnchantingHighLevel,60668,150000,@EnchantingSkill,425,0), -- Crusher
(@EnchantingHighLevel,47900,150000,@EnchantingSkill,425,0), -- Super Health
(@EnchantingHighLevel,74189,30000,@EnchantingSkill,425,0), -- Earthen Vitality
(@EnchantingHighLevel,74132,30000,@EnchantingSkill,425,0), -- Mastery
(@EnchantingHighLevel,74191,30000,@EnchantingSkill,425,0), -- Mighty Stats
(@EnchantingHighLevel,74192,30000,@EnchantingSkill,435,0), -- Lesser Power
(@EnchantingHighLevel,74193,30000,@EnchantingSkill,435,0), -- Speed
(@EnchantingHighLevel,74197,30000,@EnchantingSkill,450,0), -- Avalanche
(@EnchantingHighLevel,74195,30000,@EnchantingSkill,450,0), -- Mending
(@EnchantingHighLevel,74199,30000,@EnchantingSkill,455,0), -- Haste
(@EnchantingHighLevel,74198,30000,@EnchantingSkill,455,0), -- Haste
(@EnchantingHighLevel,74201,30000,@EnchantingSkill,460,0), -- Critical Strike
(@EnchantingHighLevel,74200,30000,@EnchantingSkill,460,0), -- Stamina
(@EnchantingHighLevel,74202,30000,@EnchantingSkill,465,0), -- Intellect
(@EnchantingHighLevel,74207,30000,@EnchantingSkill,465,0), -- Protection
(@EnchantingHighLevel,74211,30000,@EnchantingSkill,470,0), -- Elemental Slayer
(@EnchantingHighLevel,74212,30000,@EnchantingSkill,470,0), -- Exceptional Strength
(@EnchantingHighLevel,95471,30000,@EnchantingSkill,470,0), -- Mighty Agility
(@EnchantingHighLevel,74213,30000,@EnchantingSkill,475,0), -- Major Agility
(@EnchantingHighLevel,74214,30000,@EnchantingSkill,475,0), -- Mighty Resilience
(@EnchantingHighLevel,74220,30000,@EnchantingSkill,480,0), -- Greater Haste
(@EnchantingHighLevel,74223,30000,@EnchantingSkill,480,0), -- Hurricane
(@EnchantingHighLevel,74225,30000,@EnchantingSkill,485,0), -- Heartsong
(@EnchantingHighLevel,74226,30000,@EnchantingSkill,485,0), -- Mastery
(@EnchantingHighLevel,74230,30000,@EnchantingSkill,490,0), -- Critical Strike
(@EnchantingHighLevel,74229,30000,@EnchantingSkill,490,0), -- Superior Dodge
(@EnchantingHighLevel,74231,30000,@EnchantingSkill,495,0), -- Exceptional Spirit
(@EnchantingHighLevel,74232,30000,@EnchantingSkill,495,0), -- Precision
(@EnchantingHighLevel,110400,600000,@EnchantingSkill,500,85), -- Enchanting Rank 8
(@EnchantingHighLevel,116497,20000,@EnchantingSkill,500,0), -- Mysterious Essence
(@EnchantingHighLevel,74234,30000,@EnchantingSkill,500,0), -- Prootection
(@EnchantingHighLevel,74235,30000,@EnchantingSkill,500,0), -- Superior Intellect
(@EnchantingHighLevel,104338,20000,@EnchantingSkill,500,0), -- Mastery
(@EnchantingHighLevel,104404,20000,@EnchantingSkill,500,0), -- Superior Critical Strike
(@EnchantingHighLevel,74236,30000,@EnchantingSkill,505,0), -- Precision
(@EnchantingHighLevel,74237,30000,@EnchantingSkill,505,0), -- Exceptional Spirit
(@EnchantingHighLevel,74269,30000,@EnchantingSkill,510,0), -- Greater Haste
(@EnchantingHighLevel,74240,30000,@EnchantingSkill,510,0), -- Greater Intellect
(@EnchantingHighLevel,74238,30000,@EnchantingSkill,510,0), -- Mastery
(@EnchantingHighLevel,104698,30000,@EnchantingSkill,515,0), -- Maelstrom Shatter
(@EnchantingHighLevel,104430,20000,@EnchantingSkill,525,0), -- Elemental Force
(@EnchantingHighLevel,104416,20000,@EnchantingSkill,525,0), -- Greater Haste
(@EnchantingHighLevel,104408,20000,@EnchantingSkill,525,0), -- Greater Precision
(@EnchantingHighLevel,104385,20000,@EnchantingSkill,525,0), -- Major Dodge
(@EnchantingHighLevel,104393,20000,@EnchantingSkill,525,0), -- Mighty Spirit
(@EnchantingHighLevel,104392,20000,@EnchantingSkill,525,0), -- Super Resilience
(@EnchantingHighLevel,104403,20000,@EnchantingSkill,525,0), -- Superior Intellect
(@EnchantingHighLevel,118237,20000,@EnchantingSkill,535,0), -- Mysterious Diffusion
(@EnchantingHighLevel,116498,20000,@EnchantingSkill,550,0), -- Ethereal Shard
(@EnchantingHighLevel,104398,20000,@EnchantingSkill,550,0), -- Accuracy
(@EnchantingHighLevel,104409,20000,@EnchantingSkill,550,0), -- Blurred Speed
(@EnchantingHighLevel,104407,20000,@EnchantingSkill,550,0), -- Greater Haste
(@EnchantingHighLevel,104417,20000,@EnchantingSkill,550,0), -- Superior Haste
(@EnchantingHighLevel,104397,20000,@EnchantingSkill,550,0), -- Superior Stamina
(@EnchantingHighLevel,104425,20000,@EnchantingSkill,550,0), -- Windsong
(@EnchantingHighLevel,104440,20000,@EnchantingSkill,575,0), -- Colossus
(@EnchantingHighLevel,104395,20000,@EnchantingSkill,575,0), -- Glorious Stats
(@EnchantingHighLevel,130758,20000,@EnchantingSkill,575,0), -- Greater Parry
(@EnchantingHighLevel,104401,20000,@EnchantingSkill,575,0), -- Greater Protection
(@EnchantingHighLevel,104445,20000,@EnchantingSkill,575,0), -- Major Intellect
(@EnchantingHighLevel,104414,20000,@EnchantingSkill,575,0), -- Pandaren's Step
(@EnchantingHighLevel,104419,20000,@EnchantingSkill,575,0), -- Super Strength
(@EnchantingHighLevel,104420,20000,@EnchantingSkill,575,0), -- Superior Mastery
(@EnchantingHighLevel,118238,20000,@EnchantingSkill,585,0), -- Ethereal Shatter
(@EnchantingHighLevel,116499,20000,@EnchantingSkill,600,0), -- Sha Crystal
(@EnchantingHighLevel,118239,20000,@EnchantingSkill,600,0), -- Sha Shatter
-- Enchanting-LowlLevel --
(@EnchantingLowLevel,7411,10,0,0,5), -- Enchanting Rank 1
(@EnchantingLowLevel,14293,50,@EnchantingSkill,10,0), -- Lesser Magic Wand
(@EnchantingLowLevel,7420,50,@EnchantingSkill,15,0), -- Minor Health
(@EnchantingLowLevel,7426,100,@EnchantingSkill,40,0), -- Minor Absorbtion
(@EnchantingLowLevel,7457,250,@EnchantingSkill,50,0), -- Minor Stamina
(@EnchantingLowLevel,7748,250,@EnchantingSkill,60,0), -- Lesser Health
(@EnchantingLowLevel,7771,200,@EnchantingSkill,70,0), -- Minor Protection
(@EnchantingLowLevel,14807,200,@EnchantingSkill,70,0), -- Greater Magic Wand
-- Enchanting-Trainer --
(1317,-@EnchantingHighLevel,0,0,0,0), -- Lucan Cordell - Stormwind City
(3011,-@EnchantingHighLevel,0,0,0,0), -- Teg Dawnstrider - Thunder Bluff
(3345,-@EnchantingHighLevel,0,0,0,0), -- Godan - Orgrimmar
(3606,-@EnchantingHighLevel,0,0,0,0), -- Alanna Raveneye - Teldrassil
(4213,-@EnchantingHighLevel,0,0,0,0), -- Taladan - Darnassus
(4616,-@EnchantingHighLevel,0,0,0,0), -- Lavinia Crowe - Undercity
(5157,-@EnchantingHighLevel,0,0,0,0), -- Gimble Thistlefuzz - Ironforge
(5695,-@EnchantingHighLevel,0,0,0,0), -- Vance Undergloom - Tirisfal Glades
(11072,-@EnchantingHighLevel,0,0,0,0), -- Kitta Firewind - Elwynn Forest
(11073,-@EnchantingHighLevel,0,0,0,0), -- Annora - Uldaman
(11074,-@EnchantingHighLevel,0,0,0,0), -- Hgarth - Stonetalon Mountains
(16160,-@EnchantingHighLevel,0,0,0,0), -- Magistrix Eredania - Eversong Woods
(16633,-@EnchantingHighLevel,0,0,0,0), -- Sedana - Silvermoon City
(16725,-@EnchantingHighLevel,0,0,0,0), -- Nahogg - The Exodar
(18753,-@EnchantingHighLevel,0,0,0,0), -- Felannia - Hellfire Peninsula
(18773,-@EnchantingHighLevel,0,0,0,0), -- Johan Barnes - Hellfire Peninsula
(19251,-@EnchantingHighLevel,0,0,0,0), -- Enchantress Volali - Shattrath City
(19252,-@EnchantingHighLevel,0,0,0,0), -- High Enchanter Bardolan - Shattrath City
(26906,-@EnchantingHighLevel,0,0,0,0), -- Elizabeth Jackson - Howling Fjord
(26980,-@EnchantingHighLevel,0,0,0,0), -- Eorain Dawnstrike - Borean Tundra
(26990,-@EnchantingHighLevel,0,0,0,0), -- Alxis Marlowe - Borean Tundra
(28693,-@EnchantingHighLevel,0,0,0,0), -- Enchanter Nalthanis - Dalaran
(33583,-@EnchantingHighLevel,0,0,0,0), -- Fael Morningsong - Icecrown
(33610,-@EnchantingHighLevel,0,0,0,0), -- Enchanting - Shattrath City
(33633,-@EnchantingHighLevel,0,0,0,0), -- Enchantress Andiala - Shattrath City
(33676,-@EnchantingHighLevel,0,0,0,0), -- Zurii - Shattrath City
(53410,-@EnchantingHighLevel,0,0,0,0), -- Lissah Spellwick - Dustwallow Marsh
(65127,-@EnchantingHighLevel,0,0,0,0), -- Lai the Spellpaw - The Jade Forest
(85914,-@EnchantingHighLevel,0,0,0,0), -- Bil Sparktonic - Stormshield
(86027,-@EnchantingHighLevel,0,0,0,0);  -- Hane'ke - Warspear

-- Enchanting Rank 8
-- Add rank 8 Enchanting to spell_ranks
-- first_spell_id = 7411
-- spell_id = 110400
-- rank = 8
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 7411 && `rank` = 8;
INSERT INTO `spell_ranks` (`first_spell_id`,`spell_id`,`rank`) VALUES (7411,110400,8);

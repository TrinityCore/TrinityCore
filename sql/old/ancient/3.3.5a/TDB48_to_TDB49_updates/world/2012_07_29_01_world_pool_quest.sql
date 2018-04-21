SET @pool_id := 356;

DELETE FROM `pool_template` WHERE `entry` IN (@pool_id, @pool_id+1);
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@pool_id,1,'Wind Trader Zhareem - Daily Quests'),
(@pool_id+1,1,'Nether-Stalker Mah''duun - Daily Quests');

DELETE FROM `pool_quest` WHERE `entry` IN (11369,11384,11382,11363,11362,11375,11354,11386,11373,11378,11374,11372,11368,11388,11499,11370) AND `pool_entry` = @pool_id;
DELETE FROM `pool_quest` WHERE `entry` IN (11389,11371,11376,11383,11364,11500,11385,11387) AND `pool_entry` = @pool_id+1;
INSERT INTO `pool_quest` (`entry`,`pool_entry`,`description`) VALUES
(11369,@pool_id,'Wanted: A Black Stalker Egg'),
(11384,@pool_id,'Wanted: A Warp Splinter Clipping'),
(11382,@pool_id,'Wanted: Aeonus''s Hourglass'),
(11363,@pool_id,'Wanted: Bladefist''s Seal'),
(11362,@pool_id,'Wanted: Keli''dan''s Feathered Stave'),
(11375,@pool_id,'Wanted: Murmur''s Whisper'),
(11354,@pool_id,'Wanted: Nazan''s Riding Crop'),
(11386,@pool_id,'Wanted: Pathaleon''s Projector'),
(11373,@pool_id,'Wanted: Shaffar''s Wondrous Pendant'),
(11378,@pool_id,'Wanted: The Epoch Hunter''s Head'),
(11374,@pool_id,'Wanted: The Exarch''s Soul Gem'),
(11372,@pool_id,'Wanted: The Headfeathers of Ikiss'),
(11368,@pool_id,'Wanted: The Heart of Quagmirran'),
(11388,@pool_id,'Wanted: The Scroll of Skyriss'),
(11499,@pool_id,'Wanted: The Signet Ring of Prince Kael''thas'),
(11370,@pool_id,'Wanted: The Warlord''s Treatise'),
(11389,@pool_id+1,'Wanted: Arcatraz Sentinels'),
(11371,@pool_id+1,'Wanted: Coilfang Myrmidons'),
(11376,@pool_id+1,'Wanted: Malicious Instructors'),
(11383,@pool_id+1,'Wanted: Rift Lords'),
(11364,@pool_id+1,'Wanted: Shattered Hand Centurions'),
(11500,@pool_id+1,'Wanted: Sisters of Torment'),
(11385,@pool_id+1,'Wanted: Sunseeker Channelers'),
(11387,@pool_id+1,'Wanted: Tempest-Forge Destroyers');

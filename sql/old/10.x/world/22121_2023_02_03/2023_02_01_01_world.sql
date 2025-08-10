SET @SGROUP := 326;

SET @NY_EVENT := 6;
SET @LF_EVENT := 7;
SET @LA_EVENT := 8;
SET @NG_EVENT := 9;
SET @MF_EVENT := 1;
SET @CW_EVENT := 10;
SET @FS_EVENT := 72;
SET @PD_EVENT := 50;
SET @BF_EVENT := 24;
SET @HF_EVENT := 11;
SET @HE_EVENT := 12;
SET @DOD_EVENT := 51;
SET @PB_EVENT := 26;
SET @WV_EVENT := 2;
SET @WVP_EVENT := 52;

-- Holiday Spawn Groups
DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SGROUP+0 AND @SGROUP+16;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SGROUP+0, 'Holiday - Commoners', 32),
(@SGROUP+1, 'Holiday - New Year Celebration', 32),
(@SGROUP+2, 'Holiday - Lunar Festival', 32),
(@SGROUP+3, 'Holiday - Love is in the Air', 32),
(@SGROUP+4, 'Holiday - Noblegarden', 32),
(@SGROUP+5, 'Holiday - Children''s Week', 32),
(@SGROUP+6, 'Holiday - Midsummer Fire Festival', 32),
(@SGROUP+7, 'Holiday - Fireworks Spectacular', 32),
(@SGROUP+8, 'Holiday - Pirates'' Day', 32),
(@SGROUP+9, 'Holiday - Brewfest', 32),
(@SGROUP+10, 'Holiday - Harvest Festival', 32),
(@SGROUP+11, 'Holiday - Hallow''s End', 32),
(@SGROUP+12, 'Holiday - Day of the Dead', 32),
(@SGROUP+13, 'Holiday - Pilgrim''s Bounty', 32),
(@SGROUP+14, 'Holiday - Feast of Winter Veil', 32),
(@SGROUP+15, 'Holiday - Feast of Winter Veil - Presents', 32),
(@SGROUP+16, 'Holiday - Feast of Winter Veil - Stolen Treats', 36);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SGROUP+0 AND @SGROUP+16;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33,0,@SGROUP+0,0,0,12,0,@LF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Lunar Festival" is active'),
(33,0,@SGROUP+0,0,1,12,0,@NG_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Noblegarden" is active'),
(33,0,@SGROUP+0,0,2,12,0,@MF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Midsummer Fire Festival" is active'),
(33,0,@SGROUP+0,0,3,12,0,@PD_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Pirates'' Day" is active'),
(33,0,@SGROUP+0,0,4,12,0,@BF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Brewfest" is active'),
(33,0,@SGROUP+0,0,5,12,0,@HE_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Hallow''s End" is active'),
(33,0,@SGROUP+0,0,6,12,0,@DOD_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Day of the Dead" is active'),
(33,0,@SGROUP+0,0,7,12,0,@PB_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Pilgrim''s Bounty" is active'),
(33,0,@SGROUP+0,0,8,12,0,@WV_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Commoners" if event "Feast of Winter Veil" is active'),
(33,0,@SGROUP+1,0,0,12,0,@NY_EVENT,0,0,0,0,0,'','Spawn group "Holiday - New Year Celebration" only if event "New Year Celebration" is active'),
(33,0,@SGROUP+2,0,0,12,0,@LF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Lunar Festival" only if event "Lunar Festival" is active'),
(33,0,@SGROUP+3,0,0,12,0,@LA_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Love is in the Air" only if event "Love is in the Air" is active'),
(33,0,@SGROUP+4,0,0,12,0,@NG_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Noblegarden" only if event "Noblegarden" is active'),
(33,0,@SGROUP+5,0,0,12,0,@CW_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Children''s Week" only if event "Children''s Week" is active'),
(33,0,@SGROUP+6,0,0,12,0,@MF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Midsummer Fire Festival" only if event "Midsummer Fire Festival" is active'),
(33,0,@SGROUP+7,0,0,12,0,@FS_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Fireworks Spectacular" only if event "Fireworks Spectacular" is active'),
(33,0,@SGROUP+8,0,0,12,0,@PD_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Pirates'' Day" only if event "Pirates'' Day" is active'),
(33,0,@SGROUP+9,0,0,12,0,@BF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Brewfest" only if event "Brewfest" is active'),
(33,0,@SGROUP+10,0,0,12,0,@HF_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Harvest Festival" only if event "Harvest Festival" is active'),
(33,0,@SGROUP+11,0,0,12,0,@HE_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Hallow''s End" only if event "Hallow''s End" is active'),
(33,0,@SGROUP+12,0,0,12,0,@DOD_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Day of the Dead" only if event "Day of the Dead" is active'),
(33,0,@SGROUP+13,0,0,12,0,@PB_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Pilgrim''s Bounty" only if event "Pilgrim''s Bounty" is active'),
(33,0,@SGROUP+14,0,0,12,0,@WV_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Feast of Winter Veil" only if event "Feast of Winter Veil" is active'),
(33,0,@SGROUP+15,0,0,12,0,@WVP_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Feast of Winter Veil - Presents" only if event "Feast of Winter Veil - Presents" is active'),
(33,0,@SGROUP+16,0,0,12,0,@WV_EVENT,0,0,0,0,0,'','Spawn group "Holiday - Feast of Winter Veil - Stolen Treats" only if event "Feast of Winter Veil" is active');

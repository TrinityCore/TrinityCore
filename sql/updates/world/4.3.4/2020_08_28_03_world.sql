ALTER TABLE `creature_formations`   
	CHANGE `leaderGUID` `LeaderGUID` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
	CHANGE `memberGUID` `MemberGUID` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
	CHANGE `dist` `FollowDistance` FLOAT UNSIGNED NOT NULL,
	CHANGE `angle` `FollowAngle` FLOAT UNSIGNED NOT NULL,
	CHANGE `groupAI` `GroupAI` INT(10) UNSIGNED NOT NULL,
	CHANGE `point_1` `InversionPoint1` INT(5) DEFAULT -1 NULL,
	CHANGE `point_2` `InversionPoint2` INT(5) DEFAULT -1 NULL;

UPDATE `creature_formations` SET `InversionPoint1` = -1 WHERE `InversionPoint1`= 0;
UPDATE `creature_formations` SET `InversionPoint2` = -1 WHERE `InversionPoint2`= 0;

ALTER TABLE `quest_template` ADD COLUMN `ClassOrSkill` smallint(6) NOT NULL default '0' AFTER `ZoneOrSort`;

UPDATE `quest_template` SET `ClassOrSkill`=182 WHERE `ZoneOrSort`=-24;
UPDATE `quest_template` SET `ClassOrSkill`=356 WHERE `ZoneOrSort`=-101;
UPDATE `quest_template` SET `ClassOrSkill`=164 WHERE `ZoneOrSort`=-121;
UPDATE `quest_template` SET `ClassOrSkill`=171 WHERE `ZoneOrSort`=-181;
UPDATE `quest_template` SET `ClassOrSkill`=165 WHERE `ZoneOrSort`=-182;
UPDATE `quest_template` SET `ClassOrSkill`=202 WHERE `ZoneOrSort`=-201;
UPDATE `quest_template` SET `ClassOrSkill`=197 WHERE `ZoneOrSort`=-264;
UPDATE `quest_template` SET `ClassOrSkill`=185 WHERE `ZoneOrSort`=-304;
UPDATE `quest_template` SET `ClassOrSkill`=129 WHERE `ZoneOrSort`=-324;

UPDATE `quest_template` SET `ClassOrSkill`=-9 WHERE `ZoneOrSort`=-61;
UPDATE `quest_template` SET `ClassOrSkill`=-1 WHERE `ZoneOrSort`=-81;
UPDATE `quest_template` SET `ClassOrSkill`=-7 WHERE `ZoneOrSort`=-82;
UPDATE `quest_template` SET `ClassOrSkill`=-2 WHERE `ZoneOrSort`=-141;
UPDATE `quest_template` SET `ClassOrSkill`=-8 WHERE `ZoneOrSort`=-161;
UPDATE `quest_template` SET `ClassOrSkill`=-4 WHERE `ZoneOrSort`=-162;
UPDATE `quest_template` SET `ClassOrSkill`=-3 WHERE `ZoneOrSort`=-261;
UPDATE `quest_template` SET `ClassOrSkill`=-5 WHERE `ZoneOrSort`=-262;
UPDATE `quest_template` SET `ClassOrSkill`=-11 WHERE `ZoneOrSort`=-263;

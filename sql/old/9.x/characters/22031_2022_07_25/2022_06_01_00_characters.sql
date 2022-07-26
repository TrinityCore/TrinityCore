ALTER TABLE `gm_complaint`
  ADD `reportType` int NOT NULL DEFAULT '0' AFTER `complaintType`,
  ADD `reportMajorCategory` int NOT NULL DEFAULT '0' AFTER `reportType`,
  ADD `reportMinorCategoryFlags` int NOT NULL DEFAULT '0' AFTER `reportMajorCategory`;

UPDATE `gm_complaint` SET `reportType`=0,`reportMajorCategory`=0,`reportMinorCategoryFlags`=0x1 WHERE `complaintType`=2;
UPDATE `gm_complaint` SET `reportType`=1,`reportMajorCategory`=3,`reportMinorCategoryFlags`=0x800 WHERE `complaintType`=4;
UPDATE `gm_complaint` SET `reportType`=1,`reportMajorCategory`=2,`reportMinorCategoryFlags`=0x40 WHERE `complaintType`=15;
UPDATE `gm_complaint` SET `reportType`=1,`reportMajorCategory`=3,`reportMinorCategoryFlags`=0x1000 WHERE `complaintType`=23;
UPDATE `gm_complaint` SET `reportType`=0,`reportMajorCategory`=0,`reportMinorCategoryFlags`=0x4 WHERE `complaintType`=24;

ALTER TABLE `gm_complaint` DROP `complaintType`;

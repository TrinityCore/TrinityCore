-- remove all riding pamphlets from level 20 rewards
DELETE FROM `mail_level_reward`
WHERE `mailTemplateId` IN (224,231,226,225,233,229,228,230,232,227);

DELETE FROM `mail_loot_template`
WHERE `Entry` IN (224,231,226,225,233,229,228,230,232,227);

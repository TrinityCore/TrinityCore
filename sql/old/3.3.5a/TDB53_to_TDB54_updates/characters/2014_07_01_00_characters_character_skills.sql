-- Set fist weapon skill equal to current unarmed skill value
UPDATE character_skills cs_unarmed INNER JOIN character_skills cs_fist ON cs_unarmed.guid = cs_fist.guid
SET cs_fist.value = cs_unarmed.value, cs_fist.max = cs_unarmed.max
WHERE cs_unarmed.skill = 162 AND cs_fist.skill = 473;

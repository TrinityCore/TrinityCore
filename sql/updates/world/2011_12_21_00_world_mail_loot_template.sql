-- Reward from Stolen Winter Veil Treats (horde)
SET @mail:=117; -- Set in DBC
UPDATE quest_template SET RewMailTemplateId=@mail, RewMailDelaySecs=86400 WHERE entry IN (6963); -- Set mail delivery

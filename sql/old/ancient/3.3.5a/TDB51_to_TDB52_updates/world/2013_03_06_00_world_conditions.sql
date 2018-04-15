-- Delete condition that can cause some damage reduction "spikes" leading to leaking damage,
-- or in simple language some delay can cause not applying.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=56438;

-- fix Rider of the Unholy / Blood / Frost (issue #17817)
UPDATE `smart_scripts` SET `target_type`=27 WHERE `source_type`=0 AND `entryorguid` IN (30954,30956,30953) AND `action_type`=33;

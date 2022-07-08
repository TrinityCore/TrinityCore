--
UPDATE `smart_scripts` SET `action_param2` = `action_param2` &~ 2 WHERE `event_type` = 2 AND
`action_type` = 11 AND `action_param2` & 2 AND `source_type` = 0 AND `event_flags` & 1 = 0 AND
((`entryorguid` = 2038 AND `action_param1` = 774) OR
(`entryorguid` = 2566 AND `action_param1` = 4955) OR
(`entryorguid` = 2564 AND `action_param1` = 4955) OR
(`entryorguid` = 2562 AND `action_param1` = 4955) OR
(`entryorguid` = 1096 AND `action_param1` = 4979) OR
(`entryorguid` = 4723 AND `action_param1` = 4979) OR
(`entryorguid` = 2192 AND `action_param1` = 5915) OR
(`entryorguid` = 28214 AND `action_param1` = 52748) OR
(`entryorguid` = 28965 AND `action_param1` = 52879) OR
(`entryorguid` = 28961 AND `action_param1` = 52891) OR
(`entryorguid` = 28121 AND `action_param1` = 52969) OR
(`entryorguid` = 28961 AND `action_param1` = 59173) OR
(`entryorguid` = 28965 AND `action_param1` = 59181));

-- Replace with flag 1 in case of non-repeatable events, we'll deal with flag 1 later
UPDATE `smart_scripts` SET `action_param2` = `action_param2` &~ 2, `action_param2` = `action_param2` |1 WHERE
`event_type` = 2 AND `action_type` = 11 AND `action_param2` & 2 AND `source_type` = 0 AND `event_flags` & 1 AND
((`entryorguid` = 660 AND `action_param1` = 8599) OR
(`entryorguid` = 698 AND `action_param1` = 8599) OR
(`entryorguid` = 17626 AND `action_param1` = 8599) OR
(`entryorguid` = 702 AND `action_param1` = 8599) OR
(`entryorguid` = 588 AND `action_param1` = 8599) OR
(`entryorguid` = 1061 AND `action_param1` = 8599) OR
(`entryorguid` = 4392 AND `action_param1` = 9461) OR
(`entryorguid` = 7727 AND `action_param1` = 11969) OR
(`entryorguid` = 30017 AND `action_param1` = 15588) OR
(`entryorguid` = 28961 AND `action_param1` = 19134) OR
(`entryorguid` = 12801 AND `action_param1` = 20223) OR
(`entryorguid` = 2305 AND `action_param1` = 21988) OR
(`entryorguid` = 6227 AND `action_param1` = 22519) OR
(`entryorguid` = 23285 AND `action_param1` = 32714) OR
(`entryorguid` = 19188 AND `action_param1` = 33903) OR
(`entryorguid` = 19188 AND `action_param1` = 33903) OR
(`entryorguid` = 19940 AND `action_param1` = 36595) OR
(`entryorguid` = 19940 AND `action_param1` = 36596) OR
(`entryorguid` = 19940 AND `action_param1` = 36597) OR
(`entryorguid` = 22355 AND `action_param1` = 38949) OR
(`entryorguid` = 30023 AND `action_param1` = 42745) OR
(`entryorguid` = 29621 AND `action_param1` = 50161) OR
(`entryorguid` = 30017 AND `action_param1` = 50420) OR
(`entryorguid` = 27971 AND `action_param1` = 51832) OR
(`entryorguid` = 30423 AND `action_param1` = 56732) OR
(`entryorguid` = 28416 AND `action_param1` = 57861) OR
(`entryorguid` = 31015 AND `action_param1` = 58137) OR
(`entryorguid` = 28579 AND `action_param1` = 61369) OR
(`entryorguid` = 27971 AND `action_param1` = 61513));

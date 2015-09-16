--
update `smart_scripts` set `event_flags`=(`event_flags`|1) where
`entryorguid` in (619,2287,2719,3987,10817,17210) and
`source_type` = 0 and
`action_type` in (25,39);
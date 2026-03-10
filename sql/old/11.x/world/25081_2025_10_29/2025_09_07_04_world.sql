-- action_param4 used to be 'action invoker', it's been moved to flag = 4 in action_param5
UPDATE smart_scripts SET action_param5 = action_param5 | 4, action_param4 = 0 WHERE action_type = 12 AND action_param4 > 0;

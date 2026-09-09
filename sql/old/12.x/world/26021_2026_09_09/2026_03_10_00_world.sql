DELETE FROM `command` WHERE `name` IN ('debug modifiertree','debug playercondition','debug wsexpression');
INSERT INTO `command` (`name`, `help`) VALUES
('debug modifiertree', 'Syntax: .debug modifiertree #modifierTreeId\r\n\r\nChecks if ModifierTree #modifierTreeId conditions are met for targeted player.'),
('debug playercondition', 'Syntax: .debug playercondition #playerConditionId\r\n\r\nChecks if PlayerCondition #playerConditionId condition is met for targeted player.'),
('debug wsexpression', 'Syntax: .debug wsexpression #worldStateExpressionId\r\n\r\nChecks if WorldStateExpression #worldStateExpressionId condition is met on current map.');

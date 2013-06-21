-- Improved health funnel desaparece en el parche 401
Delete from spell_script_names where Scriptname = 'spell_warl_health_funnel';
-- Ya no existe Improved health stone ni tiene rangos
Delete from spell_script_names where Scriptname = 'spell_warl_create_healthstone';
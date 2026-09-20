"""Validated, bounded telemetry protocol for the read-only world viewer."""
from __future__ import annotations

from typing import Literal

from pydantic import BaseModel, ConfigDict, Field

MAX_AGENTS = 10_000
MAX_REQUEST_BYTES = 8 * 1024 * 1024
STALE_AFTER_MS = 5_000


class ProtocolModel(BaseModel):
    model_config = ConfigDict(extra="forbid", allow_inf_nan=False)


class Position(ProtocolModel):
    x: float
    y: float
    z: float
    map_id: int = Field(ge=0)
    source: Literal["live", "spawn", "last_known"]


class Needs(ProtocolModel):
    health_pressure: float = Field(ge=0, le=1)
    hunger: float = Field(ge=0, le=1)
    fatigue: float = Field(ge=0, le=1)
    safety_pressure: float = Field(ge=0, le=1)
    resource_pressure: float = Field(ge=0, le=1)


class Agent(ProtocolModel):
    agent_id: int = Field(ge=0)
    spawn_id: int = Field(ge=0)
    entry: int | None = Field(default=None, ge=0)
    name: str | None = Field(default=None, max_length=200)
    type: str = Field(max_length=80)
    control_mode: str = Field(max_length=80)
    world_faction: int | str
    world_state: str = Field(max_length=80)
    simulation_tier: str = Field(max_length=80)
    position: Position
    health: int | None = Field(default=None, ge=0)
    max_health: int | None = Field(default=None, ge=0)
    alive: bool | None = None
    in_combat: bool | None = None
    needs: Needs
    goal: str | None = Field(default=None, max_length=120)
    goal_utility: float | None = None
    action: str | None = Field(default=None, max_length=120)
    routine_goal: str | None = Field(default=None, max_length=120)
    group_id: int | None = Field(default=None, ge=0)


class TelemetryBatch(ProtocolModel):
    version: Literal[1]
    captured_at_ms: int = Field(ge=0)
    agents: list[Agent] = Field(max_length=MAX_AGENTS)

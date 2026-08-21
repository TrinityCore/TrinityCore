"""Empty AI bridge — health endpoint only (Etapa 1, section 1.11).

Decision protocol, GPU inference and the AgentContext contract are added in
Etapa 2 (section 2.9). This service exists so worldserver has something to
reach on the internal Docker network from the start.
"""
from fastapi import FastAPI

app = FastAPI(title="ai-server", version="0.1.0")


@app.get("/health")
def health() -> dict:
    return {"status": "ok"}

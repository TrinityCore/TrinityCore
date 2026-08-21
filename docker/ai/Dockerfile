# Empty AI bridge (Etapa 1 / section 1.11). Only exposes a health endpoint
# for now; decision-making logic is added in Etapa 2.
FROM python:3.11-slim

WORKDIR /app

RUN pip install --no-cache-dir fastapi uvicorn

COPY app/ ./app/

EXPOSE 8000

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]

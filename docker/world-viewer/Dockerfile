FROM python:3.11-slim

WORKDIR /app

RUN pip install --no-cache-dir "fastapi>=0.115,<1" "uvicorn>=0.30,<1" "httpx>=0.27,<1"

COPY app/ ./app/
COPY tests/ ./tests/

EXPOSE 8000

CMD ["uvicorn", "app.main:app", "--host", "0.0.0.0", "--port", "8000"]

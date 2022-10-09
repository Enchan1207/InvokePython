#
#
#
FROM ubuntu:latest

COPY ./build /app/
WORKDIR /app
CMD ["cli/invokepython_cli"]

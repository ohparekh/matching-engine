# matching-engine

A low-latency limit order book matching engine, built in C++20.

Core design: a single-threaded matching core (deterministic, no locking on the
book itself) fed by a lock-free ingress queue, benchmarked for throughput and
tail latency. This mirrors how real exchange cores are built (e.g. the LMAX
Disruptor pattern) rather than relying on fine-grained locking.

## Status

Early development — scaffolding and CI/CD pipeline in progress.

## Roadmap

- [ ] Core order book (price-time priority, limit orders, partial fills)
- [ ] Lock-free single-producer/multi-producer ingress queue
- [ ] Benchmark harness (throughput, p50/p99/p999 latency)
- [ ] Historical order-flow replay
- [ ] Simple market-making strategy on top of the engine
- [ ] Write-ahead log + crash recovery

## Build

```
cmake --preset default
cmake --build --preset default
ctest --preset default
```

## Docker

```
docker build -t matching-engine .
docker run --rm matching-engine
```

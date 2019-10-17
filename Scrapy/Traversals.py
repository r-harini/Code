def dfs(start_url):
    from collections import deque
    visited=set()
    queue=deque()
    queue.append(start_url)
    while queue:
        url=queue.popleft()
        if url in visited:
            continue
        visited.add(url)
        for link in get_links(url):
            queue.appendleft(link)
        print(url)

def bfs(start_url):
    from collections import deque
    visited=set()
    queue=deque()
    queue.append(start_url)
    while queue:
        url=queue.popleft()
        if url in visited:
            continue
        visited.add(url)
        queue.extend(get_link(url))
        print(url)
let source = EventSource.make("url");

let onOpenHandler = (e: Dom.event) => Js.log2("EventSource opened", e); 
EventSource.onOpen(source, onOpenHandler);

let onMessageHandler = (m: EventSource.MessageEvent.t) => Js.log2("EventSource message", EventSource.MessageEvent.data(m)); 
EventSource.onMessage(source, onMessageHandler);


EventSource.close(source);
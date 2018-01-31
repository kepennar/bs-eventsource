
module MessageEvent = {
  type t;
  [@bs.get] external data : t => 'a = "";
};

[@bs.deriving jsConverter]
type readyState =
  | [@bs.as 0] CONNECTING /** The connection has not yet been established, or it was closed and the user agent is reconnecting. */
  | [@bs.as 1] OPEN /** The user agent has an open connection and is dispatching events as it receives them. */
  | [@bs.as 2] CLOSED; /** The connection is not open, and the user agent is not trying to reconnect. Either there was a fatal error or the close() method was invoked. */

type eventSourceOpts = {
  .
  withCredentials: bool
};

type eventSource = {
  .
  "url": string,
  "withCredentials": bool,
  "readyState": readyState,
  "onOpen": unit => {.},
  "onMessage": unit => {.},
  "onError": unit => {.},
  "close": unit => unit
};

[@bs.new] external make : string => eventSource = "EventSource";
[@bs.new] external makeWithoption : (string, eventSourceOpts) => eventSource = "EventSource";

[@bs.set] external onOpen : (eventSource, Dom.event => unit) => unit = "onopen";
[@bs.set] external onMessage : (eventSource, MessageEvent.t => unit) => unit = "onmessage";
[@bs.set] external onError : (eventSource, Dom.event => unit) => unit = "onerror";
[@bs.set] external close : (eventSource, unit => unit) => unit = "close";
[@bs.set] external addEventListener : (eventSource, (string, MessageEvent.t => unit) => unit) => unit = "addEventListener";
[@bs.set] external removeEventListener : (eventSource, (string, MessageEvent.t => unit) => unit) => unit = "addEventListener";

## What happen if Client disconnected?

Basically, when Client disconnected, Server will wait for a period of time (which has been re-setted in `Global.asax` or default of SignalR). After that time, Client may trigger `$.connection.hub.stop()` and Server will call `OnDisconnected()` method (if not override).

My solution is to get used the method which has been designed for that on the Server, and used other method on the same `class` to `setState` for others.

My class may look like this

```
public class MyHub: Hub {
  private static Dictionary<string, string> Store = new Dictionary<string, string>();

  public void JoinGroup(string groupName) {
    Store.Add(Context.connectionId, groupName);
    Groups.Add(Context.connectionId, groupName);
  }
  public void UpdateState(bool status, int type, string groupName) {
    switch(type) {
      case 1:
        Clients.Group(groupName).UpdateState(status, type);
        break;
      case 2:
        Clients.Group(CONSTANT.GROUPNAME).UpdateState(status, type);
        break;
      case 3:
        Clients.Group(CONSTANT.GROUPNAME).UpdateState(status, type);
        break;
      case default:
        break;
    }
  }
  public override Task OnDisconnect(paraDef) {
    string delGroupName;
    Store.TryGetValue(Context.connectionId, out delGroupName);
    if (!String.IsNullOrEmpty(delGroupName)) {
      changeStateGroup = "GROUP_" + delGroupName.Split('_')[1];
      UpdateState(false, 1, changeStateGroup);
      UpdateState(false, 3, changeStateGroup);
    }
    return def;
  }
}
```

Every time Client connect via `$.connection.hub.start()`, they may call `$.connection.viewHub.server.joinGroup()` and on Server, it get `connectionId` from Context and `groupName` via parameter.

Because SignalR does not control `connectionId, groupName` as a List to be seen by dev so I have to use a Dictionary to store it statically.

On `UpdateState()`, as I want to send `heartbeat status`, I use `type = 1, 3` to send that, while `type = 2` only call once.

For Main Screen, which send heartbeats to other, its group must be `layoutName_relateScreenId`. While Relate Screen might be `GROUP_relateScreenId`. For this, I just update State of all related screens while keeping state of other main screens.

## To Do List
* Change `layoutname` to `layoutId`
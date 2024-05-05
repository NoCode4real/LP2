% hrlp desk management

response("hi", "hello").
response("check my room", "ok wait for 2 min , ur room is at xyz location").
response("room", "let me check , room xyz is at yuo location").
response("ok ", "do u need more help").
response("bye", "have a good day sir").

chat :-
    write("bola: "),
    read_line_to_codes(user_input,Input),
    atom_codes(AtomInput, Input),
    atom_string(AtomInput, StringInput),
    process_input(StringInput).
    

process_input(Input):-
    response(Input, Response),
    !,
    write("bot: "),
    writeln(Response),
    chat.
    
process_input(_) :-
    writeln("bot: I'm sorry, I don't understand."),
    chat.

:-initialization(chat).
    
    
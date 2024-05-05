% Define the responses same for chat bot
response("hello", "Hello! How can I help you?").
response("how are you", "I'm just a computer program, so I don't have feelings, but thank you for asking!").
response("goodbye", "Goodbye! Have a great day!").
response(_, "I'm sorry, I don't understand.").

% Define the main predicate for the chatbot
chat :-
    write("You: "),
    read_line_to_codes(user_input, Input),
    atom_codes(AtomInput, Input),
    atom_string(AtomInput, StringInput),
    process_input(StringInput).

% Process the input and generate a response
process_input(Input) :-
    response(Input, Response),
    !,
    write("Bot: "),
    writeln(Response),
    chat.
process_input(Input) :-
    response(_, Response), % Default response
    write("Bot: "),
    writeln(Response),
    chat.

% Entry point
:- initialization(chat).

import { Component } from '@angular/core';

@Component({
  selector: 'app-board',
  templateUrl: './board.component.html',
  styleUrls: ['./board.component.css']
})
export class BoardComponent {
  status: string = "Next player: X";
  squares: string[] = Array(9).fill(null);
  xNext: boolean = true;

  onNotify(square_id: number) {
    // if the square is already filled, do nothing
    if (this.squares[square_id] || calculateWinner(this.squares))
      return;

    // update the square with the current player
    this.squares[square_id] = (this.xNext ? "X" : "O");

    // Check if after the move, there is a winner. If so, update the status.
    const winner: string | null = calculateWinner(this.squares);
    if (winner) {
      this.status = "Winner: " + winner;
      return;
    }

    if (this.squares.every((square) => square != null)) {
      this.status = "Draw";
      return;
    }

    // Otherwise, update the status to show the next player
    this.xNext = !this.xNext;
    this.status = "Next player: " + (this.xNext ? "X" : "O");
  }
}


function calculateWinner(squares: any) {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
  ];
  for (let i = 0; i < lines.length; i++) {
    const [a, b, c] = lines[i];
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
}
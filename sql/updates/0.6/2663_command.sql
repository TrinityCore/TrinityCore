UPDATE command SET help=replace(help,"Usage:","Syntax:") WHERE left(help,6)="Usage:";


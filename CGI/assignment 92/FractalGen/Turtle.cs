using System;
using System.Collections.Generic;
using System.Drawing;

namespace JakubLevy
{
  class Turtle : IDisposable
  {
    /// <summary>
    ///   Constructor for Turtle class
    /// </summary>
    /// <param name="sentence"> drawing grammar </param>
    /// <param name="lineLength"> length of the drawing line </param>
    /// <param name="rotationAngle"> determines the rotation amount when + or - </param>
    /// <param name="startingPoint">the starting location to draw</param>
    /// <param name="directionPoint"> (1,0) means "right", (-1, 0) means left, (0,1) means down, (0,-1) means up </param>
    /// <param name="colors"> associated colors with moving letter </param>
    public Turtle (string sentence, double lineLength, double rotationAngle, Point startingPoint,
      Point directionPoint, Dictionary<char, Color> colors)
    {
      Sentence = sentence;
      LineLength = lineLength;
      RotationAngle = rotationAngle;
      StartingPoint = startingPoint;
      DirectionPoint = directionPoint;
      Colors = colors;
      Render();
    }

    public string Sentence { get; }
    public double LineLength { get; }
    public double RotationAngle { get; }
    public Point StartingPoint { get; }

    public Point DirectionPoint { get; }

    public Dictionary<char, Color> Colors { get; }

    public List<DrawInfo> DrawInfo { get; } = new List<DrawInfo>(); //all information needed to redraw a fractal

    public int Top { get; private set; } = int.MaxValue;
    public int Bottom { get; private set; } = int.MinValue;
    public int Left { get; private set; } = int.MaxValue;
    public int Right { get; private set; } = int.MinValue;

    public int Width => Right - Left;
    public int Height => Bottom - Top;

    public int Size => Math.Max(Width, Height);

    /// <summary>
    ///   Disconnects the panel from Turtle and releases memory
    /// </summary>
    public void Dispose ()
    {
      Colors.Clear();
      DrawInfo.Clear();
    }

    private void Render ()
    {
      State currentState = new State {Location = StartingPoint, CurrentAngle = 0};
      Stack<State> states = new Stack<State>();
      for (int i = 0; i < Sentence.Length; ++i)
      {
        if (Lsystem.IsNotMovingChar(Sentence[i]))
        {
          switch (Sentence[i])
          {
            case '+':
              currentState.CurrentAngle += RotationAngle;
              break;
            case '-':
              currentState.CurrentAngle -= RotationAngle;
              break;
            case '[':
              states.Push(currentState);
              break;
            case ']':
              if (states.Count > 0)
              {
                currentState = states.Pop();
              }
              else
              {
                Utils.ShowErrorMessageBox("Bad grammar");
                return;
              }

              break;
          }
        }
        else
        {
          //moving
          PointF shift = Utils.ScaleVector(Utils.RotateVector(DirectionPoint, currentState.CurrentAngle), LineLength);
          if (char.IsLower(Sentence[i]))
          {
            currentState.Location = Utils.AddVectors(currentState.Location, shift);
          }
          else //drawing 
          {
            Color c = Color.Black;
            if (Colors.ContainsKey(Sentence[i]))
            {
              c = Colors[Sentence[i]];
            }

            PointF newLocation = Utils.AddVectors(currentState.Location, shift);
            Pen p = new Pen(c);

            DrawInfo.Add(new DrawInfo {Start = currentState.Location, End = newLocation, Pen = p});
            currentState.Location = newLocation;

            if (currentState.Location.X < Left)
            {
              Left = (int)currentState.Location.X;
            }

            if (currentState.Location.X > Right)
            {
              Right = (int)currentState.Location.X;
            }

            if (currentState.Location.Y < Top)
            {
              Top = (int) currentState.Location.Y;
            }

            if (currentState.Location.Y > Bottom)
            {
              Bottom = (int) currentState.Location.Y;
            }
          }
        }
      }
    }
  }

  struct State
  {
    public PointF Location { get; set; }
    public double CurrentAngle { get; set; }
  }

  class DrawInfo
  {
    public PointF Start { get; set; }
    public PointF End { get; set; }
    public Pen Pen { get; set; }
  }
}
